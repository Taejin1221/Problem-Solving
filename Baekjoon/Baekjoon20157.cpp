// Baekjoon20157_ShootTheArrow.cpp
// https://www.acmicpc.net/problem/20157
#include <iostream>
#include <map>

using namespace std;

struct Gradient {
	int x, y;
	Gradient( ): x(0), y(0) { }
	Gradient( int x, int y ): x(x), y(y) { }
	bool operator<( const Gradient& g2 ) const {
		if ( x != g2.x )
			return x < g2.x;
		else
			return y < g2.y;
	}
};

int GCD( int a, int b ) {
	return ( b ? GCD ( b, a % b ) : a );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int maxBalloon = 0;
	map<Gradient, int> table;
	while ( n-- ) {
		int x, y;
		cin >> x >> y;

		int gcd = ( x > y ) ? GCD( x, y ) : GCD( y, x );
		gcd *= ( gcd < 0 ) ? -1 : 1;

		Gradient tempGradient = Gradient( x / gcd, y / gcd );

		if ( table[tempGradient] )
			table[tempGradient]++;
		else
			table[tempGradient] = 1;

		maxBalloon = max( maxBalloon, table[tempGradient] );
	}

	cout << maxBalloon << '\n';

	return 0;
}
