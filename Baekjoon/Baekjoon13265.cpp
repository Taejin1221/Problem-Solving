// Baekjoon13265.cpp
// https://www.acmicpc.net/problem/13265
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

bool bfs(vector<int>* adjList, int* colorInfo, int start) {
	queue<int> q;

	q.push(start);
	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int& next : adjList[curr]) {
			if (!colorInfo[next]) {
				colorInfo[next] = -colorInfo[curr];
				q.push(next);
			} else {
				if (colorInfo[next] == colorInfo[curr])
					return false;
			}
		}
	}

	return true;
}

bool solve() {
	int n, m;
	cin >> n >> m;

	vector<int> adjList[1'001];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	bool ans = true;
	int colorInfo[1'001] = { 0, };
	for (int i = 1; i <= n; i++) {
		if (!colorInfo[i]) {
			colorInfo[i] = 1;
			ans &= bfs(adjList, colorInfo, i);
		}
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		if (solve())
			cout << "possible";
		else
			cout << "impossible";
		cout << '\n';
	}

	return 0;
}