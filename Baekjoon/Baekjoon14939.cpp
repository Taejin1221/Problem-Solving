// Baekjoon14939.cpp
// https://www.acmicpc.net/problem/14939
#include <iostream>

#define ON 'O'
#define OFF '#'
#define INF 1'234'567'890

using namespace std;

void pressSwitch(bool isTurnOn[][10], int row, int col) {
	isTurnOn[row][col] = !isTurnOn[row][col];
	isTurnOn[row - 1][col] = !isTurnOn[row - 1][col];
	if (0 < col)
		isTurnOn[row][col - 1] = !isTurnOn[row][col - 1];
	if (row < 9)
		isTurnOn[row + 1][col] = !isTurnOn[row + 1][col];
	if (col < 9)
		isTurnOn[row][col + 1] = !isTurnOn[row][col + 1];
}

int getMinimumPressSwitch(bool isTurnOn[][10]) {
	int ans = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (isTurnOn[i - 1][j]) {
				pressSwitch(isTurnOn, i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (isTurnOn[i][j])
				return INF;
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool basicIsTurnOn[10][10] = { false, };
	for (int i = 0; i < 10; i++) {
		char str[11];
		cin >> str;
		for (int j = 0; j < 10; j++)
			basicIsTurnOn[i][j] = (str[j] == ON);
	}

	int ans = INF;
	for (int state = 0; state < 1024; state++) {
		bool copyIsTurnOn[10][10];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				copyIsTurnOn[i][j] = basicIsTurnOn[i][j];

		int tempAns = 0;
		for (int j = 0; j < 10; j++) {
			if (state & (1 << j)) {
				pressSwitch(copyIsTurnOn, 0, j);
				tempAns++;
			}
		}

		ans = min(ans, getMinimumPressSwitch(copyIsTurnOn) + tempAns);
	}

	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
	cout << '\n';

	return 0;
}