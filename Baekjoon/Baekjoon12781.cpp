// Baekjoon12781_PIZZAALVOLOC.cpp
// https://www.acmicpc.net/problem/12781
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int CCW( pii l1, pii l2, pii l3 );

int main(void) {
	pii lines[4];
	for ( int i = 0; i < 4; i++ )
		cin >> lines[i].first >> lines[i].second;

	int direction = CCW( lines[0], lines[2], lines[3] ) * CCW( lines[1], lines[2], lines[3] );
	int nonParrel = CCW( lines[0], lines[1], lines[2] ) && CCW( lines[0], lines[1], lines[3] );
	if ( direction < 0 && nonParrel )
		cout << 1;
	else
		cout << 0;
	cout << '\n';

	return 0;
}

int CCW( pii l1, pii l2, pii l3 ) {
	int op = (l2.first - l1.first) * (l3.second - l1.second );
	op -= (l2.second - l1.second) * (l3.first - l1.first );

	if ( op == 0 )
		return 0;
	else {
		if ( op > 0 )
			return 1;
		else
			return -1;
	}
}