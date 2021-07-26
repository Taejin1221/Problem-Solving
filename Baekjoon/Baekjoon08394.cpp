// Baekjoon08394.cpp
// https://www.acmicpc.net/problem/8394
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int f1 = 1, f2 = 2, f3;
	for (int i = 3; i <= n; i++) {
		f3 = (f1 + f2) % 10;
		f1 = f2;
		f2 = f3;
	}

	cout << f2 << '\n';

	return 0;
}