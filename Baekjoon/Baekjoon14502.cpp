// Baekjoon14502_Laboratory.cpp
// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( int r, int c ): row(r), col(c) { }
};

int row, col, maxSafeArea;
int lab[8][8];

int SpreadVirus( vector< vector<int> >& lab );
void Backtracking( int wallNumber );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> row >> col;

	for ( int i = 0; i < row; i++ )
		for ( int j = 0; j < col; j++ )
			cin >> lab[i][j];

	Backtracking( 0 );

	cout << maxSafeArea << '\n';

	return 0;
}

int SpreadVirus( int currLab[][8] ) {
	bool visited[8][8] = { false, };

	for ( int i = 0; i < row; i++ ) {
		for ( int j = 0; j < col; j++ ) {
			if ( currLab[i][j] == 2 && !visited[i][j] ) {
				queue<Position> q;
				q.push( Position( i, j ) );

				visited[i][j] = true;
				while ( !q.empty() ) {
					Position curr = q.front(); q.pop();

					Position nexts[4] = {
						Position( curr.row - 1, curr.col ),
						Position( curr.row, curr.col + 1 ),
						Position( curr.row + 1, curr.col ),
						Position( curr.row, curr.col - 1 )
					};

					for ( Position& next : nexts ) {
						if ( (0 <= next.row && next.row < row) && (0 <= next.col && next.col < col) ) {
							if ( currLab[next.row][next.col] == 0 ) {
								currLab[next.row][next.col] = 2;
								visited[next.row][next.col] = true;
								q.push( next );
							}
						}
					}
				}
			}
		}
	}

	int currSafeArea = 0;
	for ( int i = 0; i < row; i++ )
		for ( int j = 0; j < col; j++)
			if ( currLab[i][j] == 0 )
				currSafeArea++;

	return currSafeArea;
}

void Backtracking( int wallNumber ) {
	if ( wallNumber == 3 ) {
		int temp[8][8];
		for ( int i = 0; i < row; i++ )
			for ( int j = 0; j < col; j++ )
				temp[i][j] = lab[i][j];

		maxSafeArea = max( maxSafeArea, SpreadVirus( temp ) );
	} else {
		for ( int i = 0; i < row; i++ ) {
			for ( int j = 0; j < col; j++ ) {
				if ( lab[i][j] == 0 ) {
					lab[i][j] = 1;
					Backtracking( wallNumber + 1 );
					lab[i][j] = 0;
				}
			}
		}
	}
}
