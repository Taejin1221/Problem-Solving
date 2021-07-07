// Baekjoon02630_MakeColorPaper.cpp
// https://www.acmicpc.net/problem/2630
#include <iostream>

using namespace std;

struct Positon {
	int row, col, range;
	Positon(): row(0), col(0), range(0) {}
	Positon( int s, int e, int r ): row(s), col(e), range(r) {}
	Positon( Positon p, int r ): row(p.row), col(p.col), range(r) {}
};

int white, blue;
int paper[128][128];

bool isValid( int color, Positon start );
void recursion( Positon start );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> paper[i][j];

	recursion( Positon( 0, 0, n ) );

	cout << white << '\n';
	cout << blue << '\n';

	return 0;
}

bool isValid( int color, Positon start ) {
	int row = start.row, col = start.col;
	for ( int i = 0; i < start.range; i++ )
		for ( int j = 0; j < start.range; j++ )
			if ( color != paper[row + i][col + j] )
				return false;
	return true;
}

void recursion( Positon start ) {
	int color = paper[start.row][start.col];
	if ( isValid( color, start ) ) {
		if ( color )
			blue++;
		else
			white++;
	} else {
		int half = start.range / 2;
		recursion( Positon( start, half ) );
		recursion( Positon( start.row, start.col + half, half ) );
		recursion( Positon( start.row + half, start.col, half ) );
		recursion( Positon( start.row + half, start.col + half, half ) );
	}	
}