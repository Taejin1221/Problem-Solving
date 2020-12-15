// Baekjoon01965_PutBox.cpp
// https://www.acmicpc.net/problem/1965
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int dp[1'000], ans = 1;
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[i] = 1;
		for ( int j = i; j < n; j++ ) {
			if ( arr[i] < arr[j] )
				dp[i] = max( dp[i], dp[j] + 1 );
		}

		ans = max( ans, dp[i] );
	}

	cout << ans << '\n';

	return 0;
}
