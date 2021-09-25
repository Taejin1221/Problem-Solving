// Baekjoon05719.cpp
// https://www.acmicpc.net/problem/5719
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int start, dest, weight;
	Node(): start(0), dest(0), weight(0) { }
	Node(int s, int d, int w): start(s), dest(d), weight(w) { }

	bool operator<(const Node& n2) const {
		return weight > n2.weight;
	}
};

bool canGo[500][500];
vector<Node> adjList[500];

int dijkstra(int start, int target, bool findAns = false) {
	int shortest[500];
	vector<int> path[500];
	priority_queue<Node> pq;

	pq.push(Node(-1, start, 0));
	fill(shortest, shortest + 500, -1);

	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();

		if (curr.dest == target) {
			if (findAns)
				return curr.weight;

			if (shortest[target] == -1 || curr.weight == shortest[target]) {
				shortest[target] = curr.weight;
				path[curr.dest].push_back(curr.start);

				queue<int> q;
				q.push(target);
				while (!q.empty()) {
					int curr = q.front(); q.pop();
					if (curr != start) {
						while (path[curr].size()) {
							canGo[path[curr].back()][curr] = false;
							q.push(path[curr].back());
							path[curr].pop_back();
						}
					}
				}
			}

			continue;
		}

		if (shortest[curr.dest] == -1) {
			shortest[curr.dest] = curr.weight;
			path[curr.dest].push_back(curr.start);

			for (Node& adj : adjList[curr.dest])
				if (shortest[adj.dest] == -1)
					if (canGo[curr.dest][adj.dest])
						pq.push(Node(curr.dest, adj.dest, curr.weight + adj.weight));
		} else if (shortest[curr.dest] == curr.weight)
			path[curr.dest].push_back(curr.start);
	}

	return shortest[target];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	while (n != 0 && m != 0) {
		int start, target;
		cin >> start >> target;

		for (int i = 0; i < n; i++) {
			adjList[i].clear();
			fill(canGo[i], canGo[i] + n, true);
		}
		
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			adjList[a].push_back(Node(a, b, c));
		}

		dijkstra(start, target);
		cout << dijkstra(start, target, true) << '\n';

		cin >> n >> m;
	}

	return 0;
}