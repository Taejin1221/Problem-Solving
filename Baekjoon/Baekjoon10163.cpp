// Baekjoon10163.cpp
// https://www.acmicpc.net/problem/10163
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int board[1001][1001] = { { 0, }, };

	for (int num = 1; num <= n; num++) {
		int row, col, width, height;
		cin >> row >> col >> height >> width;

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				board[row + i][col + j] = num;
	}

	int paper[101] = { 0, };
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			paper[board[i][j]]++;

	for (int i = 1; i <= n; i++)
		cout << paper[i] << '\n';

	return 0;
}