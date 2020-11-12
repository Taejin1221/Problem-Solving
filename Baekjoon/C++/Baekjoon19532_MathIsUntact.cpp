// Baekjoon19532_MathIsUntact.cpp
// https://www.acmicpc.net/problem/19532
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for ( int x = -999; x < 1000; x++ ) {
		for ( int y = -999; y < 1000; y++ ) {
			if ( (a * x + b * y == c) && (d * x + e * y == f ) ) {
				cout << x << ' ' << y << '\n';
				break;
			}
		}
	}

	return 0;
}