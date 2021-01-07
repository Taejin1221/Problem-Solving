// Baekjoon02448_PrintStar11.cpp
// https://www.acmicpc.net/problem/2448
#include <iostream>
#include <algorithm>

using namespace std;

struct Range {
	int start, end;
	Range( int s, int e ): start( s ), end( e ) { }
	int currRange( ) {
		return end - start + 1;
	};
};

char star[3072][6144];

void PrintStar( Range rowRange, Range colRange );

int main(void) {
	int n;
	cin >> n;

	int maxCol = n * 2 - 1;
	for ( int i = 0; i < n; i++ )
		fill( star[i], star[i] + maxCol, ' ' );

	PrintStar( Range( 0, n - 1 ), Range( 0, maxCol - 1 ) );

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < maxCol; j++ )
			cout << star[i][j];
		cout << '\n';
	}

	return 0;
}

void PrintStar( Range rowRange, Range colRange ) {
	if ( rowRange.currRange() == 3 ) {
		star[rowRange.start][colRange.start + 2] = '*';

		star[rowRange.start + 1][colRange.start + 1] = '*';
		star[rowRange.start + 1][colRange.end - 1] = '*';

		for ( int i = colRange.start; i <= colRange.end; i++ )
			star[rowRange.end][i] = '*';
	} else {
		int rowSize = rowRange.currRange(), colSize = colRange.currRange();

		int halfRow = rowSize / 2, halfCol = (colSize - 1) / 2;
		int quarter = halfCol / 2;

		PrintStar( Range( rowRange.start, rowRange.start + halfRow - 1 ),
			Range( colRange.start + quarter + 1, colRange.end - (quarter + 1) ) );

		PrintStar( Range( rowRange.start + halfRow, rowRange.end ),
			Range( colRange.start, colRange.start + halfCol - 1 ) );

		PrintStar( Range( rowRange.start + halfRow, rowRange.end ),
			Range( colRange.start + halfCol + 1, colRange.end ) );
	}
}