// Baekjoon01504.cpp
// https://www.acmicpc.net/problem/1504
#include <iostream>

#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Node {
	int vertex, weight;
	Node() {}
	Node(int v, int w): vertex(v), weight(w) {}

	bool operator<(const Node& n2) const {
		return weight > n2.weight;
	}
};

vector<Node> adjList[801];

int getShortest(int start, int end) {
	priority_queue<Node> pq;
	bool visited[801] = { false, };

	pq.push(Node(start, 0));

	int result = -1;
	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();
		if (curr.vertex == end) {
			result = curr.weight;
			break;
		}

		if (!visited[curr.vertex]) {
			visited[curr.vertex] = true;
			for (const Node& adj : adjList[curr.vertex])
				if (!visited[adj.vertex])
					pq.push(Node(adj.vertex, curr.weight + adj.weight));
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int v, u, w;
		cin >> v >> u >> w;

		adjList[v].push_back(Node(u, w));
		adjList[u].push_back(Node(v, w));
	}

	int v1, v2;
	cin >> v1 >> v2;

	int s_v1 = getShortest(1, v1), s_v2 = getShortest(1, v2);
	int v1_v2 = getShortest(v1, v2);
	int v1_e = getShortest(v1, n), v2_e = getShortest(v2, n);

	int path1 = -1, path2 = -1;
	if (!(s_v1 == -1 || v1_v2 == -1 || v2_e == -1))
		path1 = s_v1 + v1_v2 + v2_e;

	if (!(s_v2 == -1 || v1_v2 == -1 || v1_e == -1))
		path2 = s_v2 + v1_v2 + v1_e;

	if (path1 == -1 && path2 == -1)
		cout << -1;
	else if (path1 == -1)
		cout << path2;
	else if (path2 == -1)
		cout << path1;
	else
		cout << min(path1, path2);
	cout << '\n';

	return 0;
}
