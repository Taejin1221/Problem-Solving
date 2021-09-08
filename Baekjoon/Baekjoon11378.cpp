// Baekjoon11378.cpp
// https://www.acmicpc.net/problem/11378
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX_NODE 2'002

using namespace std;

vector<int> adjList[MAX_NODE];
int capacity[MAX_NODE][MAX_NODE], flowed[MAX_NODE][MAX_NODE];

int maximumFlow(int start, int sink, int time);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int start = 0, sink = n + m + 1;
	
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;

		adjList[start].push_back(i);
		capacity[start][i] = 1;
		while (t--) {
			int job;
			cin >> job;

			adjList[i].push_back(job + n);
			adjList[job + n].push_back(i);
			capacity[i][job + n] = 1;
		}
	}

	for (int i = n + 1; i <= n + m; i++) {
		adjList[i].push_back(sink);
		capacity[i][sink] = 1;
	}

	int ans = 0;
	ans += maximumFlow(start, sink, 1'000'000'000);
	for (int i = 1; i <= n; i++)
		capacity[start][i] += k;
	ans += maximumFlow(start, sink, k);

	cout << ans << '\n';

	return 0;
}

int maximumFlow(int start, int sink, int time) {
	int ans = 0;
	while (time--) {
		int path[MAX_NODE];
		fill(path, path + MAX_NODE, -1);

		queue<int> q;

		q.push(start);
		while (!q.empty() && path[sink] == -1) {
			int curr = q.front(); q.pop();

			for (int& adj : adjList[curr]) {
				if (path[adj] == -1 && capacity[curr][adj] > flowed[curr][adj]) {
					path[adj] = curr;
					if (adj == sink)
						break;

					q.push(adj);
				}
			}
		}

		if (path[sink] == -1)
			break;

		for (int curr = sink; curr != start; curr = path[curr]) {
			flowed[path[curr]][curr]++;
			flowed[curr][path[curr]]--;
		}

		ans++;
	}

	return ans;
}