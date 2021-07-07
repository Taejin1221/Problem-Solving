// Baekjoon01926_Painting.cpp
// https://www.acmicpc.net/problem/1926
#include <iostream>

#include <queue>

using namespace std;

const int moves[4][2] = { { -1 , 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int paper[500][500];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];

	int ans = 0, maxArea = 0;
	bool visited[500][500] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1 && !visited[i][j]) {
				queue<pair<int, int>> q;

				visited[i][j] = true;
				q.push({i, j});

				int area = 0;
				while (!q.empty()) {
					pair<int, int> curr = q.front(); q.pop();
					area++;

					for (int i = 0; i < 4; i++) {
						int newRow = curr.first + moves[i][0], newCol = curr.second + moves[i][1];
						if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < m)) {
							if (paper[newRow][newCol] && !visited[newRow][newCol]) {
								visited[newRow][newCol] = true;
								q.push({newRow, newCol});
							}
						}
					}
				}

				ans++;
				maxArea = max(maxArea, area);
			}
		}
	}

	cout << ans << '\n' << maxArea << '\n';

	return 0;
}