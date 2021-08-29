// Baekjoon19640.cpp
// https://www.acmicpc.net/problem/19640
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int num, line, h, d;
	Node(): num(0), line(0), h(0), d(0) { }
	Node(int n, int l, int h, int d): num(n), line(l), h(h), d(d) { }

	bool operator<(const Node& n2) const {
		if (d == n2.d) {
			if (h == n2.h)
				return line > n2.line;
			else
				return h < n2.h;
		}
		else
			return d < n2.d;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	queue<Node> employee[100'001];
	for (int i = 1; i <= n; i++) {
		int d, h;
		cin >> d >> h;

		int line = i % m;
		if (line == 0)
			line = m;
		employee[line].push(Node(i, line, h, d));
	}

	priority_queue<Node> pq;
	for (int i = 1; i <= m; i++) {
		if (!employee[i].empty()) {
			pq.push(employee[i].front());
			employee[i].pop();
		}
	}

	int ans = 0;
	while (pq.top().num != k + 1) {
		Node curr = pq.top(); pq.pop();

		if (!employee[curr.line].empty()) {
			pq.push(employee[curr.line].front());
			employee[curr.line].pop();
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}