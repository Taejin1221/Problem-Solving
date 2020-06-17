// Baekjoon11052_BuyCard.cpp
// https://www.acmicpc.net/problem/11052
#include <iostream>

using namespace std;

int main(void) {
	ios_base :: sync_with_stdio( false );
	cin.tie(NULL);

	int prices[1001];
	int dp[1001];

	int n;
	cin >> n;

	for ( int i = 1; i <= n; i++ )
		cin >> prices[i];

	dp[1] = prices[1];
	for ( int i = 2; i <= n; i++ ) {
		int maxVal = prices[i];
		for ( int j = 1; j <= i / 2; j++ ) {
			int temp = dp[j] + dp[i - j];
			if ( temp > maxVal )
				maxVal = temp;
		}
		dp[i] = maxVal;
	}

	cout << dp[n] << '\n';
	
	return 0;
}