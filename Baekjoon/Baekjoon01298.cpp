// Baekjoon01298.cpp
// https://www.acmicpc.net/problem/1298
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int matched[101];
bool visited[101];
vector<int> adjList[101];

bool dfs(int start) {
	for (int& adj : adjList[start]) {
		if (!visited[adj]) {
			visited[adj] = true;
			if (matched[adj] == -1 || dfs(matched[adj])) {
				matched[adj] = start;
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
	}

	fill(matched + 1, matched + n + 1, -1);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited + 1, visited + n + 1, false);
		if (dfs(i))
			ans++;
	}

	cout << ans << '\n';

	return 0;
}