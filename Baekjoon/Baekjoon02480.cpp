// Baekjoon02480_ThreeDice.cpp
// https://www.acmicpc.net/problem/2480
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	if ( a == b && b == c )
		cout << 10'000 + a * 1'000 << '\n';
	else if ( a != b && b != c && a != c )
		cout << max( a, max( b, c ) ) * 100 << '\n';
	else {
		if ( a == b )
			cout << 1'000 + a * 100 << '\n';
		else
			cout << 1'000 + c * 100 << '\n';
	}

	return 0;
}