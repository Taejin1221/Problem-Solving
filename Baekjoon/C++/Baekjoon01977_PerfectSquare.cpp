// Baekjoon01977_PerfectSquare.cpp
// https://www.acmicpc.net/problem/1977
#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	int sum = 0, minVal = 0, num = 0;
	for ( int i = 1; i <= 100; i++ ) {
		int square = i * i;
		if ( square > m )
			break;
		else if ( square >= n ) {
			if ( !minVal )
				minVal = square;
			sum += square;
			num++;
		}
	}

	if ( num ) {
		cout << sum << '\n';
		cout << minVal;
	} else
		cout << -1;
	cout << '\n';

	return 0;
}