// Baekjoon16568.cpp
// https://www.acmicpc.net/problem/16568
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int people, time;

	Node(): people(0), time(0) { }
	Node(int p, int t): people(p), time(t) { }
};

int main(void) {
	int n, a, b;
	cin >> n >> a >> b;

	queue<Node> q;
	q.push(Node(n, 0));

	bool visited[1'000'001] = { false, };
	visited[n] = true;

	int ans = -1;
	while (!q.empty()) {
		Node curr = q.front(); q.pop();

		if (curr.people == 0) {
			ans = curr.time;
			break;
		}

		curr.people--, curr.time++;
		if (!visited[curr.people]) {
			q.push(Node(curr.people, curr.time ));
			visited[curr.people] = true;
		}

		if (a <= curr.people && !visited[curr.people - a]) {
			q.push(Node(curr.people - a, curr.time ));
			visited[curr.people - a] = true;
		}

		if (b <= curr.people && !visited[curr.people - b]) {
			q.push(Node(curr.people - b, curr.time ));
			visited[curr.people] = true;
		}
	}

	cout << ans << '\n';

	return 0;
}