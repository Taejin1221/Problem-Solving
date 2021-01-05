// Codeforces_1472C.cpp
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

		int arr[200'000];
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		int ans = 0;
		int dp[200'000] = { 0, };
		for ( int i = n - 1; i >= 0; i-- ) {
			if ( i + arr[i] > n )
				dp[i] = arr[i];
			else
				dp[i] = arr[i] + dp[i + arr[i]];
			ans = max( ans, dp[i] );
		}

		cout << ans << '\n';
	}

	return 0;
}
