// Baekjoon09576_DivideBook.cpp
// https://www.acmicpc.net/problem/9576
#include <iostream>
#include <algorithm> /* sort() */
#include <cstring> /* memset() */

using namespace std;

bool Compare( const pair<int, int>& r1, const pair<int, int>& r2 ) {
	if ( r1.second != r2.second )
		return ( r1.second < r2.second );
	else
		return ( r1.first < r2.first );
}

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);

	int time;
	cin >> time;

	pair<int, int> wanted[1000];
	bool isRented[1000];
	while ( time-- ) {
		int n, m, rent = 0;
		cin >> n >> m;

		memset( isRented, false, n );
		for ( int i = 0; i < m; i++ )
			cin >> wanted[i].first >> wanted[i].second;
		sort( wanted, wanted + m, Compare );

		for ( int i = 0; i < m; i++ ) {
			int start = wanted[i].first, end = wanted[i].second;
			while ( start <= end && isRented[start - 1] )
				start++;

			if ( start <= end ) {
				isRented[start - 1] = true;
				rent++;
			}
		}

		cout << rent << '\n';
	}

	return 0;
}