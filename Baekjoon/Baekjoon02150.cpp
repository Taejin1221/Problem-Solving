// Baekjoon02150.cpp
// https://www.acmicpc.net/problem/2150
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX_NODE 10'001

using namespace std;

int nodeNum[MAX_NODE], numIdx;
bool visited[MAX_NODE];
vector<vector<int>> SCC;
vector<int> adjList[MAX_NODE], reverseAdjList[MAX_NODE];

void dfs1(int start) {
	visited[start] = true;
	for (int& adj : adjList[start])
		if (!visited[adj])
			dfs1(adj);

	nodeNum[numIdx++] = start;
}

void dfs2(int start) {
	visited[start] = true;
	SCC.back().push_back(start);
	for (int& adj : reverseAdjList[start])
		if (!visited[adj])
			dfs2(adj);
}

bool compare(vector<int>& v1, vector<int>& v2);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		reverseAdjList[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i])
			dfs1(i);

	fill(visited + 1, visited + n + 1, false);
	for (int i = numIdx - 1; i >= 0; i--) {
		if (!visited[nodeNum[i]]) {
			SCC.push_back(vector<int>());
			dfs2(nodeNum[i]);
		}
	}

	for (vector<int>& scc : SCC)
		sort(scc.begin(), scc.end());
	sort(SCC.begin(), SCC.end(), compare);

	cout << SCC.size() << '\n';
	for (vector<int>& scc : SCC) {
		for (int& node : scc)
			cout << node << ' ';
		cout << "-1\n";
	}
}

bool compare(vector<int>& v1, vector<int>& v2) {
	return v1[0] < v2[0];
}