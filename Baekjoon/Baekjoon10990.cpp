// Baekjoon10990.cpp
// https://www.acmicpc.net/problem/10990
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if (n == 1) {
		cout << '*';

		return 0;
	}

	for (int i = 0; i < n - 1; i++)
		cout << ' ';
	cout << '*';
	cout << '\n';

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n - i; j++)
			cout << ' ';
		cout << '*';
		for (int j = 0; j < (i - 1) * 2 - 1; j++)
			cout << ' ';
		cout << '*';
		cout << '\n';
	}

	return 0;
}
