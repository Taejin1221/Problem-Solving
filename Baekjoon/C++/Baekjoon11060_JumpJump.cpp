// Baekjoon11060_JumpJump.cpp
// https://www.acmicpc.net/problem/11060
#include <iostream>
#include <algorithm>

#define INF 1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int dp[1'000];
	fill( dp, dp + n, INF );

	dp[0] = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 1; j <= arr[i]; j++ ) {
			if ( i + j < n )
				dp[i + j] = min( dp[i + j], dp[i] + 1 );
		}
	}

	if ( dp[n - 1] == INF )
		cout << -1;
	else
		cout << dp[n - 1];
	cout << '\n';

	return 0;
}
