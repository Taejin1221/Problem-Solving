// Baekjoon04493.cpp
// https://www.acmicpc.net/problem/4493
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int p1 = 0, p2 = 0;
		for (int i = 0; i < n; i++) {
			char a, b;
			cin >> a >> b;

			if (a == 'R') {
				if (b == 'R')
					continue;
				else if (b == 'P')
					p2++;
				else
					p1++;
			} else if (a == 'P') {
				if (b == 'R')
					p1++;
				else if (b == 'P')
					continue;
				else
					p2++;
			} else {
				if (b == 'R')
					p2++;
				else if (b == 'P')
					p1++;
				else
					continue;
			}
		}

		if (p1 > p2)
			cout << "Player 1";
		else if (p1 < p2)
			cout << "Player 2";
		else
			cout << "TIE";
		cout << '\n';
	}

	return 0;
}
