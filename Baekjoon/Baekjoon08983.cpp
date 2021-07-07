// Baekjoon08983_Hunter.cpp
// https://www.acmicpc.net/problem/8983
#include <iostream>

#include <algorithm>

#define ABS( x ) ( ( ( x ) < 0 ) ? ( - ( x ) ) : ( x ) )

using namespace std;

int BinarySearch( int gun[], int size, int target );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, l;
	cin >> m >> n >> l;

	int gun[100'000];
	for ( int i = 0; i < m; i++ )
		cin >> gun[i];

	sort( gun, gun + m );

	int ans = 0;
	for ( int i = 0; i < n; i++ ) {
		int anX, anY;
		cin >> anX >> anY;

		int idx = BinarySearch( gun, m, anX );

		int distance = ABS( gun[idx] - anX ) + anY;
		if ( distance <= l )
			ans++;
	}

	cout << ans << '\n';

	return 0;
}

int BinarySearch( int gun[], int size, int target ) {
	int start = 0, end = size - 1;
	while ( start <= end ) {
		int mid = ( start + end ) / 2;
		if ( gun[mid] == target )
			return mid;
		else if ( gun[mid] < target ) {
			if ( mid == size - 1 )
				return mid;
			else {
				if ( gun[mid] < target && target <= gun[mid + 1] ) {
					if ( ABS(gun[mid] - target) < ABS(gun[mid + 1] - target) )
						return mid;
					else
						return mid + 1;
				}
				else
					start = mid + 1;
			}
		} else {
			if ( mid == 0 )
				return mid;
			else {
				if ( gun[mid - 1] <= target && target < gun[mid] ) {
					if ( ABS(gun[mid] - target) < ABS(gun[mid - 1] - target) )
						return mid;
					else
						return mid - 1;
				}
				else
					end = mid - 1;
			}
		}
	}
}