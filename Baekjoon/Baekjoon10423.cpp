// Baekjoon10423.cpp
// https://www.acmicpc.net/problem/10423
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
	int vertex, weight;
	Node(): vertex(0), weight(0) {}
	Node(int v, int w): vertex(v), weight(w) {}

	bool operator<(const Node& n2) const {
		return weight > n2.weight;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	priority_queue<Node> pq;
	for (int i = 0; i < k; i++) {
		int start;
		cin >> start;

		pq.push(Node(start, 0));
	}

	vector<Node> adjList[1'001];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back(Node(v, w));
		adjList[v].push_back(Node(u, w));
	}

	int ans = 0;
	bool visited[1'001] = { false, };
	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();
		if (!visited[curr.vertex]) {
			visited[curr.vertex] = true;

			ans += curr.weight;

			for (Node adj : adjList[curr.vertex]) {
				if (!visited[adj.vertex]) {
					pq.push(adj);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}