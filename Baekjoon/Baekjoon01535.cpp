// Baekjoon01535_Thankyou.cpp
// https://www.acmicpc.net/problem/1535
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int life[20], happy[20];
	for ( int i = 0; i < n; i++ )
		cin >> life[i];

	for ( int i = 0; i < n; i++ )
		cin >> happy[i];

	int ans = life[0] < 100 ? happy[0] : 0;
	int dp[100][20] = { 0, };
	for ( int i = 0; i < 100; i++ ) {
		if ( life[0] <= i ) {
			dp[i][0] = happy[0];
		}

		for ( int j = 1; j < n; j++ ) {
			dp[i][j] = dp[i][j - 1];

			int prevLife = i - life[j];
			if ( prevLife >= 0 )
				dp[i][j] = max( dp[i][j - 1], dp[prevLife][j - 1] + happy[j] );
			ans = max( ans, dp[i][j] );
		}
	}

	cout << ans << '\n';

	return 0;
}