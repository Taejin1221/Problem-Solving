// Baekjoon04562.cpp
// https://www.acmicpc.net/problem/4562
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;

		if (a >= b)
			cout << "MMM BRAINS";
		else
			cout << "NO BRAINS";
		cout << '\n';
	}

	return 0;
}