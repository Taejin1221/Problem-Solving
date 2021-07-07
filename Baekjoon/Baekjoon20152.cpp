// Baekjoon20152_GameAddiction.cpp
// https://www.acmicpc.net/problem/20152
#include <iostream>

using namespace std;

int main(void) {
	int s, e;
	cin >> s >> e;

	if ( s > e ) {
		int temp = s;
		s = e;
		e = temp;
	}

	long long dp[31][31] = { 0, };
	for ( int i = s; i <= e; i++ ) {
		for ( int j = s; j <= i; j++ ) {
			if ( i == s || j == s )
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	cout << dp[e][e] << '\n';

	return 0;
}