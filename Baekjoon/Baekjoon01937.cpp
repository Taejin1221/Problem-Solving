// Baekjoon01937_GreedyPanda.cpp
// https://www.acmicpc.net/problem/1937
#include <iostream>
#include <algorithm>

using namespace std;

struct Position {
	int row, col;
	Position( int r, int c ): row(r), col(c) { }
};

int n;
int forest[500][500], dp[500][500];

int dfs( int row, int col ) {
	if ( !dp[row][col] ) {
		Position nexts[4] = {
			Position( row - 1, col ),
			Position( row, col + 1 ),
			Position( row + 1, col ),
			Position( row, col - 1 ) 
		};

		int meMax = 1;
		for ( Position& next : nexts ) {
			if ( 0 <= next.row && next.row < n &&
				0 <= next.col && next.col < n ) {
				int nextRow = next.row, nextCol = next.col;
				if ( forest[row][col] < forest[nextRow][nextCol] )
					meMax = max( meMax, dfs( nextRow, nextCol ) + 1 );
			}
		}

		dp[row][col] = meMax;
	}

	return dp[row][col];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> forest[i][j];

	int ans = 0;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			ans = max( ans, dfs( i, j ) );

	cout << ans << '\n';

	return 0;
}
