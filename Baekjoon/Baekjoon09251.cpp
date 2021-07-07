// Baekjoon09251_LCS.cpp
// https://www.acmicpc.net/problem/9251
#include <cstdio>
#include <cstring>

int max( int a, int b ) {
	return ( a > b ? a : b );
}

int main(void) {
	char str1[1001], str2[1001];

	scanf("%s", str1);
	scanf("%s", str2);

	int n = strlen( str1 ), m = strlen( str2 );
	int dp[1000][1000];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( str1[i] == str2[j] ) {
				if ( i != 0 && j != 0 )
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = 1;
			} else {
				if ( i != 0 && j != 0 )
					dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
				else if ( i != 0 )
					dp[i][j] = dp[i - 1][j];
				else if ( j != 0 )
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = 0;
			}
		}
	}

	printf("%d\n", dp[n - 1][m - 1] );

	return 0;
}