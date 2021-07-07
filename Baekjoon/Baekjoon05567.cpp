// Baekjoon05567_Marriage.cpp
// https://www.acmicpc.net/problem/5567
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
	int vertex, level;
	Node(int v, int l): vertex(v), level(l) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[501];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	queue<Node> q;
	bool visited[501] = { false, };

	int ans = 0;
	q.push(Node(1, 0));
	visited[1] = true;
	while (!q.empty()) {
		Node curr = q.front(); q.pop();

		if (curr.level < 2) {
			for (int& adj : adjList[curr.vertex]) {
				if (!visited[adj]) {
					visited[adj] = true;

					ans++;
					q.push(Node(adj, curr.level + 1));
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}