// Baekjoon01010_PlaceBridge.cpp
// https://www.acmicpc.net/problem/1010
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int dp[31][31] = { 0, }; // m, n 
	for ( int i = 0; i <= 30; i++ ) {
		dp[i][0] = dp[i][i] = 1;
		for ( int j = 1; j < i; j++ ) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	while ( t-- ) {
		int n, m;
		cin >> n >> m;

		cout << dp[m][n] << '\n';
	}

	return 0;
}