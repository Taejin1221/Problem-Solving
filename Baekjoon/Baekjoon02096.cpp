// Baekjoon02096_SlidingDown.cpp
// https://www.acmicpc.net/problem/2096
#include <iostream>

using namespace std;

void CopyTable( int src[], int dst[] );
int max( int a, int b, int c );
int min( int a, int b, int c );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int maxDp[3], minDp[3];
	cin >> maxDp[0] >> maxDp[1] >> maxDp[2];
	CopyTable( maxDp, minDp );

	for ( int i = 1; i < n; i++ ) {
		int tempMax[3], tempMin[3];
		cin >> tempMax[0] >> tempMax[1] >> tempMax[2];
		CopyTable( tempMax, tempMin );

		tempMax[0] += max( maxDp[0], maxDp[1] );
		tempMax[1] += max( maxDp[0], maxDp[1], maxDp[2] );
		tempMax[2] += max( maxDp[1], maxDp[2] );

		CopyTable( tempMax, maxDp );

		tempMin[0] += min( minDp[0], minDp[1] );
		tempMin[1] += min( minDp[0], minDp[1], minDp[2] );
		tempMin[2] += min( minDp[1], minDp[2] );

		CopyTable( tempMin, minDp );
	}

	cout << max( maxDp[0], maxDp[1], maxDp[2] ) << ' ';
	cout << min( minDp[0], minDp[1], minDp[2] ) << '\n';

	return 0;
}

void CopyTable( int src[], int dst[] ) {
	for ( int i = 0; i < 3; i++ )
		dst[i] = src[i];
}

int max( int a, int b, int c ) {
	return ( max( a, max( b, c ) ) );
}
int min( int a, int b, int c ) {
	return ( min( a, min( b, c ) ) );
}
