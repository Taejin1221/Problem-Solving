// Baekjoon09252_LCS2.cpp
// https://www.acmicpc.net/problem/9252
#include <iostream>
#include <string>

using namespace std;

string max( string a, string b ) {
	return ( a.length() > b.length() ? a : b );
}

int main(void) {
	char str1[1001], str2[1001];

	cin >> str1;
	cin >> str2;

	int n = strlen( str1 ), m = strlen( str2 );
	string dp[1000][1000];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( str1[i] == str2[j] ) {
				if ( i && j ) {
					dp[i][j] = dp[i - 1][j - 1] + str1[i];
				}
				else
					dp[i][j] = str1[i];
			} else {
				if ( i && j )
					dp[i][j ] = max( dp[i - 1][j], dp[i][j - 1] );
				else if ( i )
					dp[i][j] = dp[i - 1][j];
				else if ( j )
					dp[i][j] = dp[i][j - 1];
				else
					dp[i][j] = "";
			}
		}
	}

	cout << dp[n - 1][m - 1].length() << '\n';
	cout << dp[n - 1][m - 1] << '\n';

	return 0;
}