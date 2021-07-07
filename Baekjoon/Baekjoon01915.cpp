// Baekjoon01915_BiggestSquare.cpp
// https://www.acmicpc.net/problem/1915
#include <iostream>

using namespace std;

int min( int a, int b, int c );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	char arr[1000][1000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int maxVal = 0;
	int dp[1000][1000];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			if ( arr[i][j] == '1' ) {
				if ( i > 0 && j > 0 )
					dp[i][j] = min( dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] ) + 1;
				else
					dp[i][j] = 1;

				maxVal = (maxVal < dp[i][j]) ? dp[i][j] : maxVal;
			} else
				dp[i][j] = 0;
		}
	}

	cout << maxVal * maxVal << '\n';

	return 0;
}

int min( int a, int b, int c ) {
	if ( a <= b && a <= c )
		return a;
	else if ( b <= a && b <= c )
		return b;
	else
		return c;
}