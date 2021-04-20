// Codeforces_1485B.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int n, q, k;
	cin >> n >> q >> k;

	int arr[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	long long dp[100'000]; // prefix sum
	dp[0] = arr[1] - 1 - 1;
	for ( int i = 1; i < n - 1; i++ )
		dp[i] = dp[i - 1] + arr[i + 1] - arr[i - 1] - 2;
	dp[n - 1] = dp[n - 2] + k - arr[n - 2] - 1;

	while ( q-- ) {
		int l, r;
		cin >> l >> r;

		l--, r--;
		if ( l == r )
			cout << k - 1;
		else {
			long long ans = 0ll;
			ans += arr[l + 1] - 1 - 1;
			ans += k - arr[r - 1] - 1;
			ans += dp[r - 1] - dp[l];

			cout << ans;
		}
		cout << '\n';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
