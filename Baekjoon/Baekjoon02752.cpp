// Baekjoon02752.cpp
// https://www.acmicpc.net/problem/2752
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	if (a < b) {
		if (a < c) {
			if (b < c)
				cout << a << ' ' << b << ' ' << c;
			else
				cout << a << ' ' << c << ' ' << b;
		}
		else
			cout << c << ' ' << a << ' ' << b;
	} else {
		if (b < c) {
			if (a < c)
				cout << b << ' ' << a << ' ' << c;
			else
				cout << b << ' ' << c << ' ' << a;
		} else
			cout << c << ' ' << b << ' ' << a;
	}

	cout << '\n';

	return 0;
}