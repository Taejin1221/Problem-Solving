// Baekjoon02443_PrintStar6.cpp
// https://www.acmicpc.net/problem/2443
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < i; j++ )
			cout << ' ';
		for ( int j = 0; j < ( 2 * n - ( 2 * i + 1 ) ); j++ )
			cout << '*';
		cout << '\n';
	}

	return 0;
}