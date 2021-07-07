// Baekjoon01094_Stick.cpp
// https://www.acmicpc.net/problem/1094
#include <iostream>

using namespace std;

int main(void) {
	int x;
	cin >> x;

	int ans = 0;
	for ( int i = 0; i < 7; i++ ) {
		if ( x & (1 << i) )
			ans++;
	}

	cout << ans << '\n';

	return 0;
}