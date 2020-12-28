// Codeforces_1469B.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int r_sum[201] = { 0, }, b_sum[201] = { 0, };

		int n, m;
		cin >> n;

		for ( int i = 1; i <= n; i++ ) {
			int temp;
			cin >> temp;

			r_sum[i] = r_sum[i - 1] + temp;
		}

		cin >> m;
		for ( int i = 1; i <= m; i++ ) {
			int temp;
			cin >> temp;

			b_sum[i] = b_sum[i - 1] + temp;
		}

		int ans = 0;
		for ( int i = 0; i <= n; i++ )
			for ( int j = 0; j <= m; j++ )
				ans = max( ans, r_sum[i] + b_sum[j] );

		cout << ans << '\n';
	}

	return 0;
}
