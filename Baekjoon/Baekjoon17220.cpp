// Baekjoon17220.cpp
// https://www.acmicpc.net/problem/17220
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int indegree[26];
bool visited[26];
vector<int> adjList[26];

void dfs(int curr) {
	for (int& adj : adjList[curr])
		if (!visited[adj])
			if (!(--indegree[adj]))
				dfs(adj);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;

		indegree[b - 'A']++;
		adjList[a - 'A'].push_back(b - 'A');
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		char a;
		cin >> a;

		fill(visited, visited + n, false);

		visited[a - 'A'] = true;
		indegree[a - 'A'] = 0;
		dfs(a - 'A');
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (indegree[i])
			ans++;

	cout << ans << '\n';

	return 0;
}
