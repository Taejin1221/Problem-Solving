// Baekjoon01652.cpp
// https://www.acmicpc.net/problem/1652
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char room[100][101], temp1[100][101], temp2[100][101];
	for (int i = 0; i < n; i++) {
		cin >> room[i];
		for (int j = 0; j < n; j++)
			temp1[i][j] = temp2[i][j] = room[i][j];
	}

	int garo = 0, sero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (temp1[i][j] == '.' && temp1[i][j + 1] == '.') {
				while (j < n && temp1[i][j] != 'X')
					temp1[i][j++] = 'X';
				garo++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (temp2[j][i] == '.' && temp2[j + 1][i] == '.') {
				while (j < n && temp2[j][i] != 'X')
					temp2[j++][i] = 'X';
				sero++;
			}
		}
	}

	cout << garo << ' ' << sero << '\n';

	return 0;
}