// Baekjoon23841.cpp
// https://www.acmicpc.net/problem/23841
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	string paint[50];
	for (int i = 0; i < n; i++)
		cin >> paint[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (paint[i][j] != '.')
				paint[i][m - j - 1] = paint[i][j];

		cout << paint[i] << '\n';
	}

	return 0;
}