// Baekjoon02688_Non-DecreasingDigits.cpp
// https://www.acmicpc.net/problem/2688
#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll dp[65][10] = { 0, };
	ll ans[65] = { 0, };

	for ( int i = 0; i < 10; i++ )
		dp[1][i] = 1;

	for ( int i = 0; i < 65; i++ ) {
		for ( int j = 0; j < 10; j++ ) {
			for ( int k = 0; k <= j; k++ )
				dp[i][j] += dp[i - 1][k];
			ans[i] += dp[i][j];
		}
	}

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		cout << ans[n] << '\n';
	}

	return 0;
}
