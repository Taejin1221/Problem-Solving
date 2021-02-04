// Baekjoon01509_SplitPalindrome.cpp
// https://www.acmicpc.net/problem/1509
#include <iostream>

#include <cstring>

#define SIZE 2'500

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char str[SIZE];
	cin >> str;

	int n = strlen( str );

	bool isPalin[SIZE][SIZE] = { false, };
	for ( int i = 0; i < n; i++ )
		isPalin[i][i] = true;

	for ( int distance = 1; distance < n; distance++ ) {
		for ( int i = 0; i < n - distance; i++ ) {
			int j = i + distance;
			if ( str[i] == str[j] )
				isPalin[i][j] = ( distance == 1 || isPalin[i + 1][j - 1] );
		}
	}

	int minPailn[SIZE] = { 1, };
	for ( int i = 1; i < n; i++ ) {
		if ( isPalin[0][i] )
			minPailn[i] = 1;
		else {
			minPailn[i] = i + 1;
			for ( int j = i - 1; j >= 0; j-- ) {
				if ( isPalin[j + 1][i] )
					minPailn[i] = min( minPailn[i], minPailn[j] + 1 );
			}
		}
	}

	cout << minPailn[n - 1] << '\n';

	return 0;
}