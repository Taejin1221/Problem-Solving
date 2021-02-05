// Baekjoon02133_FillTile.cpp
// https://www.acmicpc.net/problem/2133
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n % 2 )
		cout << 0;
	else {
		int dp[31] = { 1, 0, 3, };
		for ( int i = 4; i <= n; i += 2 ) {
			dp[i] += 3 * dp[i - 2];
			for ( int j = 4; j <= i; j += 2 )
				dp[i] += 2 * dp[i - j];
		}

		cout << dp[n];
	}
	cout << '\n';

	return 0;
}