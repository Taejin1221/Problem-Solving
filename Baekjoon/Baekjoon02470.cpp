// Baekjoon02470_TwoLiquid.cpp
// https://www.acmicpc.net/problem/2470
#include <iostream>
#include <algorithm>

#define ABS( a ) ( ( a ) > 0 ? ( a ) : -( a ) )

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int liquids[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> liquids[i];
	sort( liquids, liquids + n );

	int ans = 2e9, leftVal, rightVal;
	for ( int i = 0; i < n; i++ ) {
		int left = i + 1, right = n - 1;
		while ( left <= right ) {
			int mid = ( left + right ) / 2;

			int currVal = ABS( liquids[i] + liquids[mid] );
			if ( currVal < ans ) {
				ans = currVal;
				leftVal = liquids[i];
				rightVal = liquids[mid];
			}

			if ( liquids[i] + liquids[mid] < 0 )
				left = mid + 1;
			else
				right = mid - 1;
		}
	}

	cout << leftVal << ' ' << rightVal << '\n';

	return 0;
}