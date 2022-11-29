// Baekjoon11586.cpp
// https://www.acmicpc.net/problem/11586
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	char princess[100][101];
	for (int i = 0; i < n; i++)
		cin >> princess[i];

	int k;
	cin >> k;

	if (k == 1)
		for (int i = 0; i < n; i++)
			cout << princess[i] << '\n';
	else if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--)
				cout << princess[i][j];
			cout << '\n';
		}
	} else {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++)
				cout << princess[i][j];
			cout << '\n';
		}
	}

	return 0;
}
