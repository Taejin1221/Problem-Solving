// Baekjoon11054_LongestBitonicSubsequence.cpp
// https://www.acmicpc.net/problem/11054
#include <iostream>

using namespace std;

int max( int a, int b ) {
	if ( a >= b )
		return a;
	else
		return b;
}

int max( int a, int b, int c ) {
	if ( a >= b && a >= c )
		return a;
	else if ( b >= a && b >= c )
		return b;
	else
		return c;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int nums[1000];
	for ( int i = 0; i < n; i++ )
		cin >> nums[i];

	int maxVal = 1;
	int dp[2][1000]; // 0: decrease, 1: increase
	for ( int i = (n - 1); i >= 0; i-- ) {
		dp[0][i] = dp[1][i] = 1;
		for ( int j = i + 1; j < n; j++ ) {
			if ( nums[i] < nums[j] )
				dp[1][i] = max( dp[1][i], dp[0][j] + 1, dp[1][j] + 1 );
			else if ( nums[i] > nums[j] )
				dp[0][i] = max( dp[0][i], dp[0][j] + 1 );
		}
		if ( maxVal < dp[0][i] )
			maxVal = dp[0][i];
		if ( maxVal < dp[1][i] )
			maxVal = dp[1][i];
	}

	cout << maxVal << '\n';

	return 0;
}