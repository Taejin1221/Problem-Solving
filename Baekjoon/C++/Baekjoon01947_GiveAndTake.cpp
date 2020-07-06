// Baekjoon01947_GiveAndTake.cpp
// https://www.acmicpc.net/problem/1947
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n == 1 )
		cout << 0 << '\n';
	else if ( n == 2 )
		cout << 1 << '\n';
	else {
		long num1 = 0, num2 = 1, num3;
		for ( int i = 3; i <= n; i++ ) {
			num3 = ( num1 + num2 ) * ( i - 1 ) % 1000000000;
			num1 = num2;
			num2 = num3;
		}

		cout << num3 << '\n';
	}

	return 0;
}