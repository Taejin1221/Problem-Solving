// Baekjoon01780_NumberOfPaper.cpp
// https://www.acmicpc.net/problem/1780
#include <iostream>

#define endl '\n'
#define MAX 2187

using namespace std;

struct Position {
	int row, col, range;
	Position( int r ): row(0), col(0), range(r) {}
	Position( int r, int c, int ra ): row(r), col(c), range(ra) {}
};

int papers[3];
int paper[MAX][MAX];

bool isValid( int value, Position start );
void Recursion( Position start );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> paper[i][j];

	Recursion( Position( n ) );

	for ( int p : papers )
		cout << p << endl;

	return 0;
}

bool isValid( int value, Position start ) {
	for ( int i = 0; i < start.range; i++ )
		for ( int j = 0; j < start.range; j++ )
			if ( paper[start.row + i][start.col + j] != value )
				return false;
	return true;
}

void Recursion( Position start ) {
	int value = paper[start.row][start.col];
	if ( isValid( value, start ) ) {
		if ( value == -1 )
			papers[0]++;
		else if ( value == 0 )
			papers[1]++;
		else
			papers[2]++;
	} else {
		int newRange = start.range / 3;
		int doubleRange = newRange * 2;

		Recursion( Position( start.row, start.col, newRange ) );
		Recursion( Position( start.row, start.col + newRange, newRange ) );
		Recursion( Position( start.row, start.col + doubleRange, newRange ) );
		Recursion( Position( start.row + newRange, start.col, newRange ) );
		Recursion( Position( start.row + newRange, start.col + newRange, newRange ) );
		Recursion( Position( start.row + newRange, start.col + doubleRange, newRange ) );
		Recursion( Position( start.row + doubleRange, start.col, newRange ) );
		Recursion( Position( start.row + doubleRange, start.col + newRange, newRange ) );
		Recursion( Position( start.row + doubleRange, start.col + doubleRange, newRange ) );
	}
}
