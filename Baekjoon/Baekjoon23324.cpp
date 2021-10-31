// Hongik_E.cpp
#include <iostream>

#include <vector>
#include <algorithm>

#define SIZE 100'001

using namespace std;

int team[SIZE];
vector<int> adjList[SIZE];
bool visited[SIZE];

void dfs(int curr, int teamNumber) {
	team[curr] = teamNumber;
	visited[curr] = true;

	for (int& adj : adjList[curr]) {
		if (!visited[adj])
			dfs(adj, teamNumber);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int k_vertex1, k_vertex2;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (i == k)
			k_vertex1 = u, k_vertex2 = v;
		else {
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
	}

	team[k_vertex1] = 1;
	visited[k_vertex1] = true;
	for (int& adj : adjList[k_vertex1])
		if (!visited[adj] && adj != k_vertex2)
			dfs(adj, 1);

	fill(visited + 1, visited + n + 1, false);
	team[k_vertex2] = 2;
	visited[k_vertex2] = true;
	for (int& adj : adjList[k_vertex2])
		if (!visited[adj] && adj != k_vertex1)
			dfs(adj, 2);

	int team1 = 0, team2 = 0;
	for (int i = 1; i <= n; i++)
		team[i] == 1 ? team1++ : team2++;

	long long ans = 1LL * team1 * team2;
	cout << ans << '\n';

	return 0;
}