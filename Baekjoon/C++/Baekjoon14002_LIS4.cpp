// Baekjoon14002_LIS4.cpp
// https://www.acmicpc.net/problem/14002
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int ans[2] = { 0, };

	// dp[0][i] : i th lis, dp[1][i] : next lis index
	int dp[2][1'000] = { 0, };
	for ( int i = n - 1; i >= 0; i-- ) {
		dp[0][i] = 1;
		dp[1][i] = i;
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[i] < arr[j] ) {
				if ( dp[0][i] < dp[0][j] + 1 ) {
					dp[0][i] = dp[0][j] + 1;
					dp[1][i] = j;
				}
			}
		}
		
		if ( ans[0] < dp[0][i] ) {
			ans[0] = dp[0][i];
			ans[1] = i;
		}
	}

	cout << ans[0] << '\n';

	int curr = ans[1];
	while ( dp[1][curr] != curr ) {
		cout << arr[curr] << ' ';
		curr = dp[1][curr];
	}
	cout << arr[curr] << '\n';

	return 0;
}