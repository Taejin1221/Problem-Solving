// Baekjoon16928.cpp
// https://www.acmicpc.net/problem/16928
#include <iostream>

#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int nextGrid[101] = { 0, };
	for (int i = 0; i < n + m; i++) {
		int u, v;
		cin >> u >> v;

		nextGrid[u] = v;
	}

	queue<pii> q;
	bool visited[101] = { false, };

	q.push({ 1, 0 });
	visited[1] = true;

	int ans;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();

		if (curr.first == 100) {
			ans = curr.second;
			break;
		}

		for (int i = 1; i <= 6; i++) {
			int next = curr.first + i;
			if (next <= 100 && !visited[next]) {
				visited[next] = true;
				
				bool canPush = true;
				if (nextGrid[next]) {
					if (!visited[nextGrid[next]]) {
						next = nextGrid[next];
						visited[next] = true;
					} else
						canPush = false;
				}
				
				if (canPush)
					q.push({ next, curr.second + 1 });
			}
		}
	}

	cout << ans << '\n';

	return 0;
}