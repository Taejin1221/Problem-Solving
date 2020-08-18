// Baekjoon01107_Remocontroller.cpp
// https://www.acmicpc.net/problem/1107
#include <iostream>

#define abs( x ) ( ( ( x ) > 0 ) ? ( x ) : ( -( x ) ) )

using namespace std;

int target, minDiff, digit;
bool remocon[10] = { true, true, true, true, true, true, true, true, true, true };

void dfs( int curr, int idx );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> target;

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		remocon[temp] = false;
	}

	minDiff = abs( target - 100 );
	for ( digit = 1; digit <= 6; digit++ )
		dfs( 0, 0 );

	cout << minDiff << '\n';

	return 0;
}

void dfs( int curr, int idx ) {
	if ( idx == digit )
		minDiff = min( minDiff, abs( target - curr ) + digit );
	else {
		curr *= 10;
		for ( int i = 0; i < 10; i++ )
			if ( remocon[i] )
				dfs( curr + i, idx + 1 );
	}
}