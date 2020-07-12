// Baekjoon01983_NumberBox.cpp
// https://www.acmicpc.net/problem/1983
#include <iostream>

#define INF -40'000

using namespace std;

int max3( int a, int b, int c ) {
	return max( max( a, b ), c );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int top[400], bottom[400];
	int topSize = 0, bottomSize = 0;
	for ( int i = 0; i < n; i++ ) {
		cin >> top[topSize];
		if ( top[topSize] )
			topSize++;
	}

	for ( int i = 0; i < n; i++ ) {
		cin >> bottom[bottomSize];
		if ( bottom[bottomSize] )
			bottomSize++;
	}

	int dp[41][40][40];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			for ( int k = 0; k < n; k++ )
				dp[i][j][k] = INF;

	if ( topSize < n || bottomSize < n )
		dp[0][0][0] = max( top[0] * bottom[0], 0 );
	else
		dp[0][0][0] = top[0] * bottom[0];

	for ( int k = 1; k <= n; k++) {
		for ( int i = 0; i < min( k + 1, topSize ); i++ ) {
			for ( int j = 0; j < min( k + 1, bottomSize ); j++ ) {
				if ( i == 0 && j == 0 )
					dp[k][i][j] = max(top[i] * bottom[j], dp[k - 1][i][j]);
				else if ( i == 0 )
					dp[k][i][j] = max(top[i] * bottom[j], dp[k - 1][i][j - 1]);
				else if ( j == 0 )
					dp[k][i][j] = max(top[i] * bottom[j], dp[k - 1][i - 1][j]);
				else
					dp[k][i][j] = max3( dp[k - 1][i - 1][j - 1] + top[i] * bottom[j], dp[k - 1][i][j - 1], dp[k - 1][i - 1][j] );
			}
		}
	}

	cout << dp[n][topSize - 1][bottomSize - 1] << '\n';

	return 0;
}