// Baekjoon14950.cpp
// https://www.acmicpc.net/problem/14950
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using ll = long long;

struct Node {
	int vertex, weight;
	Node(int v, int w): vertex(v), weight(w) { }
	bool operator<(const Node& n2) const {
		return weight > n2.weight;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, t;
	cin >> n >> m >> t;

	vector<Node> adjList[10'001];
	for (int i = 0; i < m; i++) {
		ll v, u, w;
		cin >> v >> u >> w;

		adjList[v].push_back(Node(u, w));
		adjList[u].push_back(Node(v, w));
	}

	priority_queue<Node> pq;
	pq.push(Node(1, 0));
	bool visited[10'001] = { false, };

	ll ans = 0, conquer = 0;
	while (conquer < n && !pq.empty()) {
		Node curr = pq.top(); pq.pop();
		if (!visited[curr.vertex]) {
			visited[curr.vertex] = true;
			ans += curr.weight;
			conquer++;

			for (Node& next : adjList[curr.vertex]) {
				if (!visited[next.vertex]) {
					pq.push(Node(next.vertex, next.weight));
				}
			}
		}
	}

	cout << ans + ((n - 2) * (n - 1) / 2) * t << '\n';

	return 0;
}