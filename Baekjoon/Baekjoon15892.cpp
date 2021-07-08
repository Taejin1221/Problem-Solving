// Baekjoon15892.cpp
// https://www.acmicpc.net/problem/15892
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX_NODE 301

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[MAX_NODE];
	int capacity[MAX_NODE][MAX_NODE] = { 0, };
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
		capacity[a][b] += c;
		capacity[b][a] += c;
	}

	int ans = 0;
	int flowed[MAX_NODE][MAX_NODE] = { 0, };
	while (true) {
		queue<int> q;
		int path[MAX_NODE];

		q.push(1);
		fill(path + 1, path + n + 1, -1);
		while (!q.empty() && path[n] == -1) {
			int curr = q.front(); q.pop();
			for (int& adj : adjList[curr]) {
				if (capacity[curr][adj] > flowed[curr][adj] && path[adj] == -1) {
					path[adj] = curr;
					if (adj == n)
						break;

					q.push(adj);
				}
			}
		}

		if (path[n] == -1)
			break;

		for (int curr = n; curr != 1; curr = path[curr]) {
			flowed[path[curr]][curr]++;
			flowed[curr][path[curr]]--;
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}