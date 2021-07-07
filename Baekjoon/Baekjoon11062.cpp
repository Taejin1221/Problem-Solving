// Baekjoon11062_CardGame.cpp
// https://www.acmicpc.net/problem/11062
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		int cards[1'000], prefixSum[1'001] = { 0, };
		for ( int i = 0; i < n; i++ ) {
			cin >> cards[i];
			prefixSum[i + 1] = prefixSum[i] + cards[i];
		}

		int dp[1'000][1'000];
		for ( int i = 0; i < n; i++ )
			dp[i][i] = cards[i];

		for ( int inter = 1; inter < n; inter++ ) {
			for ( int left = 0; left < n - inter; left++ ) {
				int right = left + inter;

				int currSum = prefixSum[right + 1] - prefixSum[left];
				dp[left][right] = max( currSum - dp[left + 1][right], currSum - dp[left][right - 1] );
			}
		}

		cout << dp[0][n - 1] << '\n';
	}

	return 0;
}