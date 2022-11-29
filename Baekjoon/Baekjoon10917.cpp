// BOJ_10917.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[200'001];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		adjList[x].push_back(y);
	}

	queue<pii> q;
	bool visited[200'001] = { false, };

	q.push({ 1, 0 });
	visited[1] = true;

	int ans = -1;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();

		if (curr.first == n) {
			ans = curr.second;
			break;
		}

		for (int& adj : adjList[curr.first]) {
			if (!visited[adj]) {
				visited[adj] = true;

				q.push({ adj, curr.second + 1});
			}
		}
	}

	cout << ans << '\n';

	return 0;
}