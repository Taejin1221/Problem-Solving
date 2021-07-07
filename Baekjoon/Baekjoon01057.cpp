// Baekjoon01057_Tournament.cpp
// https://www.acmicpc.net/problem/1057
#include <iostream>

using namespace std;

int main(void) {
	int n, a, b;
	cin >> n >> a >> b;

	int ans = 1;
	while ( a != b ) {
		a = a / 2 + ( a % 2 );
		b = b / 2 + ( b % 2 );
		ans++;
	}

	cout << ans - 1 << '\n';

	return 0;
}