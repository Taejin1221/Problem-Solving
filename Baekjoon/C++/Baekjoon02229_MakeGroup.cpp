// Baekjoon02229_MakeGroup.cpp
// https://www.acmicpc.net/problem/2229
#include <iostream>

using namespace std;

int max( int scores[], int s, int e ) {
	int maxVal = scores[s];
	for ( int i = s + 1; i <= e; i++ )
		maxVal = ( maxVal < scores[i] ) ? scores[i] : maxVal;
	return maxVal;
}

int min( int scores[], int s, int e ) {
	int minVal = scores[s];
	for ( int i = s + 1; i <= e; i++ )
		minVal = ( minVal > scores[i] ) ? scores[i] : minVal;
	return minVal;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int scores[1000];
	for ( int i = 0; i < n; i++ )
		cin >> scores[i];

	int maxVal = 0;
	int dp[1000][1000] = { 0, };
	for ( int inter = 1; inter < n; inter++ ) {
		for ( int i = 0; i < n - inter; i++ ) {
			int r = i, c = i + inter;
			dp[r][c] = max( scores, r, c ) - min( scores, r, c );
			for ( int k = 1; k <= c; k++ )
				dp[r][c] = max( dp[r][c], dp[r][k - 1] + dp[k][c] );
			maxVal = max( maxVal, dp[r][c] );
		}
	}

	cout << maxVal << '\n';

	return 0;
}