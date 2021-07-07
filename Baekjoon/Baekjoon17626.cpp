// Baekjoon17626_FourSquares.cpp
// https://www.acmicpc.net/problem/17626
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int root = (int)floor( sqrt( n ) );

	bool find = false;
	for ( int i = 1; i <= root; i++ ) {
		if ( i * i == n ) {
			find = true;
			break;
		}
	}

	if ( find ) {
		cout << 1 << '\n';

		return 0;
	}

	for ( int i = 1; i <= root && !find; i++ ) {
		int i_sqare = i * i;
		for ( int j = 1; j <= root && !find; j++ ) {
			if ( i_sqare + j * j == n ) {
				find = true;
			}
		}
	}

	if ( find ) {
		cout << 2 << '\n';

		return 0;
	}

	for ( int i = 1; i <= root && !find; i++ ) {
		int i_sqare = i * i;
		for ( int j = 1; j <= root && !find; j++ ) {
			int j_square = j * j;
			for ( int k = 1; k <= root && !find; k++ )
				if ( i_sqare + j_square + k * k == n )
					find = true;
		}
	}

	if ( find )
		cout << 3 << '\n';
	else
		cout << 4 << '\n';

	return 0;
}