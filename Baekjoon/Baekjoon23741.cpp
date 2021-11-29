// Baekjoon23741.cpp
// https://www.acmicpc.net/problem/23741
#include <iostream>

#include <set>
#include <vector>

using namespace std;

set<int> ans;
bool visited[1'001][1'001];
vector<int> adjList[1'001];

void dfs(int vertex, int year) {
	if (year == 0)
		ans.insert(vertex);
	else {
		for (int& adj : adjList[vertex]) {
			if (!visited[year - 1][adj]) {
				visited[year - 1][adj] = true;
				dfs(adj, year - 1);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	dfs(x, y);

	if (ans.empty())
		cout << -1;
	else
		for (auto iter = ans.begin(); iter != ans.end(); ++iter)
			cout << *iter << ' ';
	cout << '\n';

	return 0;
}