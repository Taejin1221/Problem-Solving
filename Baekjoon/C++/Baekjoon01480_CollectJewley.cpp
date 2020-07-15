// Baekjoon01480_CollectJewley.cpp
// https://www.acmicpc.net/problem/1480
// Reference : https://github.com/kks227/BOJ/blob/master/1400/1480.cpp
#include <iostream>
#include <cstring> /* memset() */

using namespace std;

int n, m, c;
int jewels[13];
int dp[8192][11][21];

int GetMaxJewel( int got, int bag, int capacity ) {
	int& currVal = dp[got][bag][capacity];
	if ( currVal == -1 ) {
		if ( bag == 0 || got == 8191 )
			return currVal = 0;
	
		if ( capacity == 0 )
			return ( currVal = GetMaxJewel( got, bag - 1, c ) );
	
		currVal = GetMaxJewel( got, bag - 1, c );
		for ( int i = 0; i < n; i++ )
			if ( !(got & (1 << i) ) && jewels[i] <= capacity )
				currVal = max( currVal, GetMaxJewel( got | (1 << i), bag, capacity - jewels[i] ) + 1 );
	
	}

	return currVal;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> c;

	for ( int i = 0; i < n; i++ )
		cin >> jewels[i];

	memset( dp, -1, sizeof( dp ) );

	cout << GetMaxJewel( 0, m, c ) << '\n';

	return 0;
}