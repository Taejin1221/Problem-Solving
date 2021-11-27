// Baekjoon01113.cpp
// https://www.acmicpc.net/problem/1113
#include <iostream>

#include <queue>

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n, m;
char swim[50][51];

int fillWater(char height) {
	bool visited[50][50] = { false, };

	int fill = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && swim[i][j] == height) {
				bool connctedWithEdge = (i == 0 || i == n - 1 || j == 0 || j == m - 1);
				char minAdjHeight = '9';

				queue<pii> visitQ;
				queue<pii> q;
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty()) {
					pii curr = q.front(); q.pop();
					visitQ.push(curr);

					for (int k = 0; k < 4; k++) {
						int nr = curr.first + moves[k][0], nc = curr.second + moves[k][1];
						if ((0 <= nr && nr < n) && (0 <= nc && nc < m)) {
							if (swim[nr][nc] == height) {
								if (!visited[nr][nc]) {
									if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1)
										connctedWithEdge = true;
									visited[nr][nc] = true;
									q.push({ nr, nc });
								}
							} else if (swim[nr][nc] > height)
								minAdjHeight = min(minAdjHeight, swim[nr][nc]);
							else
								connctedWithEdge = true;
						}
					}
				}

				if (!connctedWithEdge) {
					fill += visitQ.size() * (minAdjHeight - height);
					while (!visitQ.empty()) {
						pii curr = visitQ.front(); visitQ.pop();
						swim[curr.first][curr.second] = minAdjHeight;
					}
				}
			}
		}
	}

	return fill;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> swim[i];

	int ans = 0, temp;
	for (char i = '1'; i <= '9'; i++)
		ans += fillWater(i);

	cout << ans << '\n';

	return 0;
}