// Baekjoon09370.cpp
// https://www.acmicpc.net/problem/9370
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int vertex, weight;
	bool isCross;

	Node(): vertex(0), weight(0), isCross(false) { }
	Node(int v, int w, bool c): vertex(v), weight(w), isCross(c) { }

	bool operator<(const Node& n2) const {
		if (weight != n2.weight)
			return weight > n2.weight;
		else
			return isCross == false && n2.isCross == true;
	}
};

void solve() {
	int n, m, t;
	cin >> n >> m >> t;

	int start, g, h;
	cin >> start >> g >> h;

	vector<Node> adjList[2'001];
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;

		bool toggle = false;
		if ((a == g && b == h) || (a == h && b == g))
			toggle = true;

		adjList[a].push_back(Node(b, d, toggle));
		adjList[b].push_back(Node(a, d, toggle));
	}

	bool isDest[2'001] = { false, };
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;

		isDest[temp] = true;
	}

	priority_queue<Node> pq;
	bool visited[2'001] = { false, };

	pq.push(Node(start, 0, false));

	vector<int> ans;
	while (!pq.empty()) {
		Node curr = pq.top(); pq.pop();

		if (!visited[curr.vertex]) {
			visited[curr.vertex] = true;
			if (isDest[curr.vertex] && curr.isCross)
				ans.push_back(curr.vertex);

			for (Node& adj : adjList[curr.vertex])
				if (!visited[adj.vertex])
					pq.push(Node(adj.vertex, curr.weight + adj.weight, adj.isCross || curr.isCross));
		}
	}

	sort(ans.begin(), ans.end());

	for (int& a : ans)
		cout << a << ' ';
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}