// BOJ_18405.cpp
#include <iostream>

#include <vector>

#define X first
#define Y second

using namespace std;

using pii = pair<int, int>;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int experiment[200][200], virusNum = 0;
	vector<pii> virusPosition[1'001];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> experiment[i][j];
			if (experiment[i][j] != 0)
				virusNum++;
				virusPosition[experiment[i][j]].push_back({ i, j });
		}
	}


	int t, x, y;
	cin >> t >> x >> y;
	while (t-- && virusNum < n * n) {
		for (int i = 1; i <= k; i++) {
			for (pii& curr : virusPosition[i]) {
				for (int j = 0; j < 4; j++) {
					int newRow = curr.X + moves[j][0], newCol = curr.Y + moves[j][1];
					if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
						if (experiment[newRow][newCol] == 0) {
							experiment[newRow][newCol] = i;
							virusNum++;
							virusPosition[i].push_back({ newRow, newCol });
						}
					}

					if (virusNum == n * n)
						break;
				}

				if (virusNum == n * n)
					break;
			}

			if (virusNum == n * n)
				break;
		}
	}

	cout << experiment[x - 1][y - 1] << '\n';

	return 0;
}