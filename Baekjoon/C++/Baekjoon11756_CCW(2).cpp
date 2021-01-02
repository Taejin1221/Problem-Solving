// Baekjoon11756_CCW(2).cpp
// https://www.acmicpc.net/problem/11758
#include <iostream>

using namespace std;

struct Coord {
	int x, y;
	Coord( ): x(0), y(0) { }
};

int CCW( Coord pos1, Coord pos2, Coord pos3 ) {
	return ( ( pos1.x * pos2.y + pos2.x * pos3.y + pos3.x * pos1.y )
		- ( pos1.y * pos2.x + pos2.y * pos3.x + pos3.y * pos1.x ) );
}

int main(void) {
	Coord pos1, pos2, pos3;

	cin >> pos1.x >> pos1.y;
	cin >> pos2.x >> pos2.y;
	cin >> pos3.x >> pos3.y;

	int ccw = CCW( pos1, pos2, pos3 );

	if ( ccw > 0 )
		cout << 1;
	else if ( ccw < 0 )
		cout << -1;
	else
		cout << 0;
	cout << '\n';

	return 0;
}