// Baekjoon01074_Z.cpp
// https://www.acmicpc.net/problem/1074
#include <iostream>

using namespace std;

struct Range {
	int row, col, range;
	Range( int r, int c, int g ): row(r), col(c), range(g) {}
};

int num, r, c;

void func( Range start );

int main(void) {
	int n;
	cin >> n >> r >> c;

	func( Range( 0, 0, 1 << n ) );

	cout << num << '\n';

	return 0;
}

void func( Range start ) {
	if ( start.range == 1 )
		return;
	else {
		int half = start.range / 2;
		int block = half * half;

		int row = start.row, col = start.col;
		if ( r < row + half && c < col + half ) {
			num += block * 0;
			func( Range( start.row, start.col, half ) );
		} else if ( r < row + half && c >= col + half ) {
			num += block * 1;
			func( Range( start.row, start.col + half, half ) );
		} else if ( r >= row + half && c < col + half ) {
			num += block * 2;
			func( Range( start.row + half, start.col, half ) );
		} else {
			num += block * 3;
			func( Range( start.row + half, start.col + half, half ) );
		}
	}
}