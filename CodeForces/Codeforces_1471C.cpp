// Codeforces_1471C.cpp
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n, m;
		cin >> n >> m;

		int friends[300'000];
		for ( int i = 0; i < n; i++ )
			cin >> friends[i];

		sort( friends, friends + n );

		ll costs[300'001];
		for ( int i = 1; i <= m; i++ ) {
			cin >> costs[i];
			costs[i] += costs[i - 1];
		}

		int diff = ( n > m ) ? n - m : 0;
		ll sum = 0ll;
		for ( int i = 0; i < diff; i++ )
			sum += costs[friends[i]] - costs[friends[i] - 1];

		ll ans = LLONG_MAX;
		for ( int i = diff; i < n; i++ ) {
			ans = min( ans, sum + costs[n - i] );

			sum += costs[friends[i]] - costs[friends[i] - 1];
		}

		cout << ans << '\n';
	}

	return 0;
}
