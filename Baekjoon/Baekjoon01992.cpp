// Baekjoon01992_QuadTree.cpp
// https://www.acmicpc.net/problem/1992
#include <iostream>

using namespace std;

struct Range {
	int start, end;
	Range( int r, int c ): start(r), end(c) {}
};

int n, comIdx;
char com[10000];
char video[64][64];

bool CanZip( const Range& row, const Range& col, char target ) {
	for ( int i = row.start; i <= row.end; i++ )
		for ( int j = col.start; j <= col.end; j++ )
			if ( video[i][j] != target)
				return false;

	return true;
}

void MakeQuadTree( const Range& row, const Range& col ) {
	char target = video[row.start][col.start];
	if ( CanZip( row, col, target ) )
		com[comIdx++] = target;
	else {
		int halfRow = ( row.end - row.start ) / 2, halfCol = ( col.end - col.start ) / 2;
		Range rowFirst = Range( row.start, row.start + halfRow ), rowSecond = Range( row.start + halfRow + 1, row.end );
		Range colFirst = Range( col.start, col.start + halfCol ), colSecond = Range( col.start + halfCol + 1, col.end );

		com[comIdx++] = '(';
		MakeQuadTree( rowFirst, colFirst );
		MakeQuadTree( rowFirst, colSecond );
		MakeQuadTree( rowSecond, colFirst );
		MakeQuadTree( rowSecond, colSecond );
		com[comIdx++] = ')';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for ( int i = 0 ; i < n; i++ )
		cin >> video[i];

	MakeQuadTree( Range( 0, n - 1 ), Range( 0, n - 1 ) );

	cout << com << '\n';

	return 0;
}