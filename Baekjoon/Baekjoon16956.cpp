// Baekjoon16956.cpp
// https://www.acmicpc.net/problem/16956
#include <iostream>

using namespace std;

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main(void) {
	int r, c;
	cin >> r >> c;

	char farm[500][501] = { { 0, } };
	for (int i = 0; i < r; i++)
		cin >> farm[i];

	int ans = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (farm[i][j] == 'S') {
				for (int k = 0; k < 4; k++) {
					int newRow = i + moves[k][0], newCol = j  + moves[k][1];
					if ((0 <= newRow && newRow < r) && (0 <= newCol && newCol < c)) {
						if (farm[newRow][newCol] == 'W') {
							ans = 0;
							break;
						} else if (farm[newRow][newCol] == '.')
							farm[newRow][newCol] = 'D';
					}
				}
			}

			if (ans == 0)
				break;
		}

		if (ans == 0)
			break;
	}

	if (ans == 0)
		cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		for (int i = 0; i < r; i++)
			cout << farm[i] << '\n';
	}

	return 0;
}