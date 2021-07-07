// Baekjoon02169_RemoteRobot.cpp
// https://www.acmicpc.net/problem/2169
#include <iostream>

#include <algorithm>

#define SIZE 1'000
#define INF -1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int value[SIZE][SIZE];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> value[i][j];

	// 0 -> from left, 1 -> from up, 2 -> from right
	int dp[3][SIZE][SIZE];
	for ( int i = 0; i < 3; i++ )
		for ( int j = 0; j < n; j++ )
			fill( dp[i][j], dp[i][j] + m, INF );

	dp[0][0][0] = value[0][0];
	dp[1][0][0] = value[0][0];
	dp[2][0][0] = value[0][0];
	for ( int i = 0; i < n; i++ ) {
		if ( i > 0 )
			for ( int j = 0; j < m; j++ )
				dp[1][i][j] = max( dp[0][i - 1][j], max( dp[1][i - 1][j], dp[2][i - 1][j] ) ) + value[i][j];

		for ( int j = 1; j < m; j++ )
			dp[0][i][j] = max( dp[0][i][j - 1], dp[1][i][j - 1] ) + value[i][j];

		for ( int j = m - 2; j >= 0; j-- )
			dp[2][i][j] = max( dp[1][i][j + 1], dp[2][i][j + 1] ) + value[i][j];
	}

	cout << max( dp[0][n - 1][m - 1], max( dp[1][n - 1][m - 1], dp[2][n - 1][m - 1] ) ) << '\n';

	return 0;
}