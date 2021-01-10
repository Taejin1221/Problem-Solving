// Baekjoon07453_Sum0FourNumber.cpp
// https://www.acmicpc.net/problem/7453
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int tableSize = n * n;

	int a[4'000], b[4'000], c[4'000], d[4'000];
	for ( int i = 0; i < n; i++ )
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int idx1 = 0;
	vector<int> table1 ( tableSize );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			table1[idx1++] = a[i] + b[j];

	int idx2 = 0;
	vector<int> table2 ( tableSize );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			table2[idx2++] = c[i] + d[j];

	sort( table2.begin(), table2.end() );

	long ans = 0l;
	for ( int i = 0; i < tableSize; i++ ) {
		int value = -table1[i];
		int upper = upper_bound( table2.begin(), table2.end(), value ) - table2.begin();
		int lower = lower_bound( table2.begin(), table2.end(), value ) - table2.begin();

		ans += upper - lower;
	}

	cout << ans << '\n';

	return 0;
}