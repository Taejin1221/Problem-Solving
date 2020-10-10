// Baekjoon02455_InteligenceTrain.cpp
// https://www.acmicpc.net/problem/2455
#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	int ans = 0, rest = 0;

	for ( int i = 0; i < 4; i++ ) {
		cin >> a >> b;
		rest = rest - a + b;

		ans = max(ans, rest);
	}

	cout << ans << '\n';

	return 0;
}