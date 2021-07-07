// Baekjoon02444_PrintStar7.cpp
// https://www.acmicpc.net/problem/2444
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	for ( int i = n - 1; i >= 0; i-- ) {
		for ( int j = 0; j < i; j++ )
			cout << ' ';
		int end = 2 * n - (2 * i + 1);
		for ( int j = 0; j < end; j++ )
			cout << '*';
		cout << '\n';
	}

	for ( int i = 1; i < n; i++ ) {
		for ( int j = 0; j < i; j++ )
			cout << ' ';

		int end = 2 * n - ( 2 * i + 1 );
		for ( int j = 0; j < end; j++ )
			cout << '*';
		cout << '\n';
	}

	return 0;
}