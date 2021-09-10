// Baekjoon02660.cpp
// https://www.acmicpc.net/problem/2660
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> adjList[51];

	int u, v;
	cin >> u >> v;
	while (u != -1 && v != -1) {
		adjList[u].push_back(v);
		adjList[v].push_back(u);

		cin >> u >> v;
	}

	pii minScore = { 100, 0 };
	int score[51] = { 0, };
	for (int i = 1; i <= n; i++) {
		queue<pii> q;
		bool visited[51] = { false, };

		q.push({ i, 0 });
		visited[i] = true;

		while (!q.empty()) {
			pii curr = q.front(); q.pop();
			score[i] = max(score[i], curr.second);

			for (int& adj : adjList[curr.first]) {
				if (!visited[adj]) {
					visited[adj] = true;

					q.push({ adj, curr.second + 1 });
				}
			}
		}

		if (minScore.first > score[i]) {
			minScore.first = score[i];
			minScore.second = 1;
		} else if (minScore.first == score[i])
			minScore.second++;
	}

	cout << minScore.first << ' ' << minScore.second << '\n';
	for (int i = 1; i <= n; i++)
		if (score[i] == minScore.first)
			cout << i << ' ';

	cout << '\n';

	return 0;
}