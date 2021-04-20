// Codeforces670_B.cpp
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long max( long long a, long long b ) {
	return ( a > b ) ? a : b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		long long arr[100'000];
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		sort( arr, arr + n );

		long long ans = LLONG_MIN;

		long long temp = 1ll;
		for ( int i = 1; i <= 5; i++ )
			temp *= arr[n - i];
		ans = max( ans, temp );

		temp = arr[0] * arr[1];
		temp *= arr[n - 1] * arr[n - 2] * arr[n - 3];
		ans = max( ans, temp );

		temp = arr[0] * arr[1] * arr[2] * arr[3];
		temp *= arr[n - 1];
		ans = max( ans, temp );

		cout << ans << '\n';
	}

	return 0;
}