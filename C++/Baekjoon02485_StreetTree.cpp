// Baekjoon02485_StreetTree.cpp
// https://www.acmicpc.net/problem/2485
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int GCD( int n, int m );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> trees ( n );
	vector<int> diffs ( n - 1);

	cin >> trees[0];
	for ( int i = 1; i < n; i++ )
		cin >> trees[i];

	sort( trees.begin(), trees.end() );
	for ( int i = 0; i < n - 1; i++ )
		diffs[i] = ( trees[i + 1] - trees[i] );

	if ( diffs.size() == 1 )
		cout << 0 << '\n';
	else {
		int gcd = GCD( diffs[0], diffs[1]);
		for ( int i = 2; i < n - 1; i++)
			gcd = GCD( gcd, diffs[i] );

		int countTree = 0;
		for ( int i = 0; i < n - 1; i++ ) {
			countTree += ( trees[i + 1] - trees[i] ) / gcd - 1;
		}

		cout << countTree << '\n';
	}

	return 0;
}

int GCD( int n, int m ) {
	if ( m == 0 )
		return n;
	else
		return GCD( m, n % m );
}
