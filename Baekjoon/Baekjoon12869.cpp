// Baekjoon12869_Mutalisk.cpp
// https://www.acmicpc.net/problem/12869
#include <iostream>

using namespace std;

int dp[61][61][61];

int solve( int a, int b, int c ) {
	if ( a < 0 )
		a = 0;

	if ( b < 0 )
		b = 0;

	if ( c < 0 )
		c = 0;

	if ( dp[a][b][c] == 100 ) {
		int curr = dp[a][b][c];
		curr = min( curr, solve( a - 9, b - 3, c - 1 ) + 1 );
		curr = min( curr, solve( a - 9, b - 1, c - 3 ) + 1 );
		curr = min( curr, solve( a - 3, b - 9, c - 1 ) + 1 );
		curr = min( curr, solve( a - 3, b - 1, c - 9 ) + 1 );
		curr = min( curr, solve( a - 1, b - 9, c - 3 ) + 1 );
		curr = min( curr, solve( a - 1, b - 3, c - 9 ) + 1 );

		dp[a][b][c] = curr;
	}

	return dp[a][b][c];
}

int main(void) {
	int n;
	cin >> n;

	for ( int i = 0; i < 61; i++ )
		for ( int j = 0; j < 61; j++ )
			for ( int k = 0; k < 61; k++ )
				dp[i][j][k] = 100;

	int scv[3] = { 0, };
	for ( int i = 0; i < n; i++ )
		cin >> scv[i];

	dp[0][0][0] = 0;
	cout << solve( scv[0], scv[1], scv[2] ) << '\n';

	return 0;
}