// Baekjoon09084_Coin.cpp
// https://www.acmicpc.net/problem/9084
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int coins[20];
		for ( int i = 0; i < n; i++ )
			cin >> coins[i];

		int target;
		cin >> target;

		int dp[10'001] = { 1, };
		for ( int i = 0; i < n; i++ )
			for ( int j = coins[i]; j <= target; j++ )
				dp[j] += dp[j - coins[i]];

		cout << dp[target] << '\n';
	}

	return 0;
}
