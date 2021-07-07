// Baekjoon02143_SumOfTwaArray.cpp
// https://www.acmicpc.net/problem/2143
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int>::iterator iter;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int target;
	cin >> target;

	int n, m;
	int a[1'000], b[1'000];
	int prefix_a[1'001] = { 0, }, prefix_b[1'001] = { 0, };

	cin >> n;
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i];
		prefix_a[i + 1] = prefix_a[i] + a[i];
	}

	cin >> m;
	for ( int i = 0; i < m; i++ ) {
		cin >> b[i];
		prefix_b[i + 1] = prefix_b[i] + b[i];
	}

	int tableSize = 0;
	vector<int> table_b ( m * ( m + 1 ) / 2 );
	for ( int i = 0; i < m; i++ )
		for ( int j = i + 1; j <= m; j++ )
			table_b[tableSize++] = prefix_b[j] - prefix_b[i];
	sort( table_b.begin(), table_b.end() );

	long long ans = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = i + 1; j <= n; j++ ) {
			int value = target - ( prefix_a[j] - prefix_a[i] );
			iter left = lower_bound( table_b.begin(), table_b.end(), value );
			iter right = upper_bound( left, table_b.end(), value );

			ans += right - left;
		}
	}

	cout << ans << '\n';

	return 0;
}