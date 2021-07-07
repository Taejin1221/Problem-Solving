// Baekjoon01629_Multiply.cpp
// https://www.acmicpc.net/problem/1629
#include <iostream>

using namespace std;

int a, b, c;

long pow( int x, int y ) {
	if ( y == 1 )
		return x;
	else { 
		long temp = pow( x, y / 2 );
		if ( y % 2 == 0 )
			return (temp * temp) % c;
		else
			return (((temp * temp) % c) * x) % c;
	}
}

int main(void) {
	cin >> a >> b >> c;

	cout << pow( a, b ) % c << '\n';

	return 0;
}