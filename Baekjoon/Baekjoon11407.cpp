// Baekjoon11407.cpp
// https://www.acmicpc.net/problem/11407
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX 202
#define INF 1'234'567'890

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; // n: book store, m: people
	cin >> m >> n;

	int start = 0, target = n + m + 1;
	vector<int> adjList[MAX];
	int capacity[MAX][MAX] = { 0, };
	int distance[MAX][MAX] = { 0, };

	for (int i = n + 1; i <= n + m; i++) {
		int a; cin >> a;
		capacity[i][target] = a;

		adjList[i].push_back(target);
	}

	for (int i = 1; i <= n; i++) {
		int b; cin >> b;
		capacity[start][i] = b;

		adjList[start].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n + 1; j <= n + m; j++) {
			cin >> capacity[i][j];
			if (capacity[i][j]) {
				adjList[i].push_back(j);
				adjList[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = n + 1; j <= n + m; j++) {
			cin >> distance[i][j];
			distance[j][i] = -distance[i][j];
		}
	}

	pair<int, int> ans = { 0, 0 };
	int flowed[MAX][MAX] = { 0, };

	while (true) {
		int path[MAX], shortestPath[MAX];

		fill(path, path + MAX, -1);
		fill(shortestPath, shortestPath + MAX, INF);

		queue<int> q;
		bool isInQ[MAX] = { false, };

		q.push(start);
		isInQ[start] = true;
		shortestPath[start] = 0;

		while (!q.empty()) {
			int curr = q.front(); q.pop();
			isInQ[curr] = false;

			for (int& adj : adjList[curr]) {
				if (capacity[curr][adj] > flowed[curr][adj] && shortestPath[adj] > shortestPath[curr] + distance[curr][adj]) {
					path[adj] = curr;
					shortestPath[adj] = shortestPath[curr] + distance[curr][adj];

					if (!isInQ[adj]) {
						isInQ[adj] = true;
						q.push(adj);
					}
				}
			}
		}

		if (path[target] == -1)
			break;

		int flow = INF;
		for (int i = target; i != start; i = path[i])
			flow = min(flow, capacity[path[i]][i] - flowed[path[i]][i]);

		ans.first += flow;
		ans.second += flow * shortestPath[target];
		for (int i = target; i != start; i = path[i]) {
			flowed[path[i]][i] += flow;
			flowed[i][path[i]] -= flow;
		}
	}

	cout << ans.first << '\n' << ans.second << '\n';

	return 0;
}