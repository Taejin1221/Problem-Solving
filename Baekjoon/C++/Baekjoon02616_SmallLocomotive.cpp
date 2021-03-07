// Baekjoon02616_SmallLocomotive.cpp
// https://www.acmicpc.net/problem/2616
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[50'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int m;
	cin >> m;

	int maxSums[50'000] = { 0, };
	for ( int i = 0; i < m; i++ )
		maxSums[0] += arr[i];

	for ( int i = 1; i <= n - m; i++ )
		maxSums[i] = maxSums[i - 1] - arr[i - 1] + arr[i + m - 1];

	int dp[4][50'000] = { 0, };
	for ( int i = 1; i <= 3; i++ )
		for ( int j = n - (m * i); j >= 0; j-- )
			dp[i][j] = max( dp[i][j], max( dp[i][j + 1], maxSums[j] + dp[i - 1][j + m] ) );

	int ans = 0;
	for ( int i = 0; i < n; i++ )
		ans = max( ans, dp[3][i] );

	cout << ans << '\n';

	return 0;
}