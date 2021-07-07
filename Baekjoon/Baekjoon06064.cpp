// Baekjoon06064_CainCalendar.cpp
// https://www.acmicpc.net/problem/6064
#include <iostream>

using namespace std;

int gcd( int a, int b ) {
	if ( b == 0 )
		return a;
	else
		return ( a % b ) ? gcd( b, a % b ) : b;
}

int lcm( int a, int b ) {
	return ( a * b ) / gcd( a, b );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int bound = ( m < n ) ? lcm( n, m ) : lcm( m, n );

		bool flag = false;
		int a = x, b = y;
		while ( !flag && (a <= bound && b <= bound) ) {
			if ( a == b )
				flag = true;
			else {
				if ( a < b )
					a += m;
				else
					b += n;
			}
		}

		if ( flag )
			cout << a << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}