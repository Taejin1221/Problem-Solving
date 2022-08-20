// Baekjoon10995.cpp
// https://www.acmicpc.net/problem/10995
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 1)
				cout << "* ";
			else
				cout << " *";
		}
		cout << '\n';
	}

	return 0;
}