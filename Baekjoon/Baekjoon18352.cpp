// Baekjoon18352.cpp
// https://www.acmicpc.net/problem/18352
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX 300'001

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<int> adjList[MAX];

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
	}

	bool visited[MAX] = { false, };

	queue<pii> q;
	vector<int> ans;

	q.push({ x, 0 });
	visited[x] = true;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();
		if (curr.second > k)
			break;

		if (curr.second == k)
			ans.push_back(curr.first);

		for (int& adj : adjList[curr.first]) {
			if (!visited[adj]) {
				visited[adj] = true;
				q.push({ adj, curr.second + 1 });
			}
		}
	}

	if (ans.size() == 0)
		cout << -1 << '\n';
	else {
		sort(ans.begin(), ans.end());

		for (int& a : ans)
			cout << a << '\n';
	}

	return 0;
}