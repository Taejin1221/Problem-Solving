// Baekjoon02525_OvenClock.cpp
// https://www.acmicpc.net/problem/2525
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	b += c;

	while ( b >= 60 ) {
		a++;
		if ( a == 24 )
			a = 0;
		b -= 60;
	}

	cout << a << ' ' << b << '\n';

	return 0;
}