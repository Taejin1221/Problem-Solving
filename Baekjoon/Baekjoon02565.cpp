// Baekjoon02565_ElectricWire.cpp
// https://www.acmicpc.net/problem/2565
#include <iostream>
#include <algorithm> /* fill() */

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[501] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int a, b;
		cin >> a >> b;

		arr[a] = b;
	}

	int str[100], strIdx = 0;
	for ( int i = 0; i < 501; i++ )
		if ( arr[i] )
			str[strIdx++] = arr[i];

	int lcs = 0;

	int dp[100];
	fill( dp, dp + n, 1 );
	for ( int i = n - 2; i >= 0; i-- ) {
		for ( int j = i + 1; j < n; j++ )
			if ( str[i] < str[j] )
				dp[i] = max( dp[i], dp[j] + 1 );

		lcs = max( lcs, dp[i] );
	}

	cout << n - lcs << '\n';

	return 0;
}