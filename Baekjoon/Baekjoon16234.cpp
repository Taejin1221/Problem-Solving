// Baekjoon16234.cpp
// https://www.acmicpc.net/problem/16234
#include <iostream>

#include <vector>

#define abs(x) ((x) > 0) ? (x) : (-(x))

using namespace std;

typedef pair<int, int> pii;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, start, end;
	cin >> n >> start >> end;

	int population[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> population[i][j];

	int time = 0;
	bool run = true;
	while (run) {
		run = false;
		bool visited[50][50] = { false, };
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (!visited[row][col]) {
					vector<pii> q;
					int uniteSum = 0, qIdx = 0;

					q.push_back({ row, col });
					visited[row][col] = true;
					uniteSum += population[row][col];

					while (qIdx < q.size()) {
						pii curr = q[qIdx++];

						for (int i = 0; i < 4; i++) {
							int newRow = curr.first + moves[i][0], newCol = curr.second + moves[i][1];
							if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
								int diff = abs(population[curr.first][curr.second] - population[newRow][newCol]);
								if (!visited[newRow][newCol] && (start <= diff && diff <= end)) {
									visited[newRow][newCol] = true;
									q.push_back({ newRow, newCol});
									uniteSum += population[newRow][newCol];
								}
							}
						}
					}

					if (q.size() > 1) {
						run = true;
						int newPopulation = uniteSum / q.size();
						while (!q.empty()) {
							pii pos = q.back(); q.pop_back();
							population[pos.first][pos.second] = newPopulation;
						}
					}
				}
			}
		}

		if (run)
			time++;
	}

	cout << time << '\n';

	return 0;
}