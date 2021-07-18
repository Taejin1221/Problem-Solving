// Baekjoon11377.cpp
// https://www.acmicpc.net/problem/11377
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX_NODE 3'001

using namespace std;

bool visited[MAX_NODE];
int jobMatching[MAX_NODE];
vector<int> adjList[MAX_NODE];

bool dfs(int start) {
	for (int& adj : adjList[start]) {
		if (!visited[adj]) {
			visited[adj] = true;
			if (jobMatching[adj] == 0 || dfs(jobMatching[adj])) {
				jobMatching[adj] = start;
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (t--) {
			int temp;
			cin >> temp;

			int jobNode = temp + 2 * n;
			adjList[i].push_back(jobNode);
			adjList[i + n].push_back(jobNode);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + MAX_NODE, false);
		if (dfs(i))
			ans++;
	}

	for (int i = n + 1; i <= 2 * n && k; i++) {
		fill(visited, visited + MAX_NODE, false);
		if (dfs(i))
			k--, ans++;
	}

	cout << ans << '\n';

	return 0;
}