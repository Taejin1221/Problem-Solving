// Baekjoon05972.cpp
// https://www.acmicpc.net/problem/5972
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Vertex {
	int adj, weight;
	Vertex(int a, int w): adj(a), weight(w) { }
	bool operator<(const Vertex& v2) const {
		return weight > v2.weight;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Vertex> adjList[50'001];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back(Vertex(v, w));
		adjList[v].push_back(Vertex(u, w));
	}

	priority_queue<Vertex> pq;
	bool visited[50'001] = { false, };

	int ans = 0;
	pq.push(Vertex(1, 0));

	while (!pq.empty()) {
		Vertex curr = pq.top(); pq.pop();
		if (curr.adj == n) {
			ans = curr.weight;
			break;
		}

		if (!visited[curr.adj]) {
			visited[curr.adj] = true;

			for (Vertex& adj : adjList[curr.adj])
				if (!visited[adj.adj])
					pq.push(Vertex(adj.adj, curr.weight + adj.weight));
		}
	}

	cout << ans << '\n';

	return 0;
}