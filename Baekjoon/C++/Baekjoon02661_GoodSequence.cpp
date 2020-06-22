// Baekjoon02661_GoodSequence.cpp
// https://www.acmicpc.net/problem/2661
#include <iostream>
#include <cstring>

using namespace std;

int n;
char sequence[81];

bool isBad( int end );
bool dfs( int idx );

int main(void) {
	memset( sequence, 0, 81 );

	cin >> n;
	dfs( 0 );

	cout << sequence << '\n';

	return 0;
}

bool isBad( int end ) {
	for ( int i = 0; i <= end / 2; i++ ) {
		int front = end - i - i - 1, back = end - i;
		if ( strncmp( sequence + front, sequence + back, (i + 1) ) == 0 )
			return true;
	}
	return false;
}

bool dfs( int idx ) {
	if ( idx && isBad( idx - 1 ) )
		return false;
	else if ( idx == n )
		return true;
	else {
		for ( char i = '1'; i <= '3'; i++ ) {
			sequence[idx] = i;
			if ( dfs( idx + 1 ) )
				return true;
		}
		sequence[idx] = 0;
		
		return false;
	}
}
