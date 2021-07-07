// Baekjoon02576_OddNumber.cpp
// https://www.acmicpc.net/problem/2576
#include <iostream>

using namespace std;

int main(void) {
	int minVal = 99;
	int sum = 0, num = 0;

	for ( int i = 0; i < 7; i++ ) {
		int curr;
		cin >> curr;

		if ( curr % 2 ) {
			minVal = min( minVal, curr );
			sum += curr;
			num++;
		}
	}

	if ( num ) {
		cout << sum << '\n';
		cout << minVal << '\n';
	} else {
		cout << -1 << '\n';
	}

	return 0;
}