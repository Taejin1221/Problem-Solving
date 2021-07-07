// Baekjoon01748_WriteContinueNumber.cpp
// https://www.acmicpc.net/problem/1748
#include <iostream>

using namespace std;

int myPow( int a, int b ) {
	int product = 1;
	for ( int i = 0; i < b; i++ )
		product *= a;
	return product;
}

int main(void) {
	int n;
	cin >> n;

	long sum = 0l;
	for ( int i = 0; i <= 8; i ++ ) {
		int compare = myPow( 10, i );
		if ( compare <= n )
			sum += ( n <= compare * 10 - 1 ) ? ( i + 1 ) * (n - compare + 1) : ( i + 1 ) * compare * 9;
	}

	cout << sum << '\n';

	return 0;
}