// Baekjoon01934_LeastCommonMultiple.cpp
// https://www.acmicpc.net/problem/1934
#include <iostream>

using namespace std;

int GCD(int a, int b ) {
	return ( a % b ) ? GCD( b, a % b ) : b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int a, b;
		cin >> a >> b;

		int gcd;
		if ( a > b )
			gcd = GCD( a, b );
		else
			gcd = GCD( b, a );

		cout << a * b / gcd << '\n';
	}

	return 0;
}