// Baekjoon01987_Alphabet.cpp
// https://www.acmicpc.net/problem/1987
#include <iostream>

using namespace std;

struct Position {
	int row, col;
	Position( int r, int c ): row(r), col(c) { }
};

int r, c, ans;
char board[20][21];
bool visited[20][20], alphabet[26];

void dfs( int, int, int );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for ( int i = 0; i < r; i++ )
		cin >> board[i];

	visited[0][0] = true;
	alphabet[board[0][0] - 'A'] = true;
	dfs( 0, 0, 1 );

	cout << ans << '\n';

	return 0;
}

void dfs( int row, int col, int curr ) {
	ans = max( ans, curr );

	Position nexts[4] = {
		Position( row - 1, col ),
		Position( row, col + 1 ),
		Position( row + 1, col ),
		Position( row, col - 1 )
	};

	for ( Position& next : nexts ) {
		if ( ( 0 <= next.row && next.row < r ) && ( 0 <= next.col && next.col < c ) ) {
			if ( !visited[next.row][next.col] ) {
				int nextAlphabet = (int)(board[next.row][next.col] - 'A');
				if ( !alphabet[nextAlphabet] ) {
					alphabet[nextAlphabet] = true;
					visited[next.row][next.col] = true;
					dfs( next.row, next.col, curr + 1 );
					alphabet[nextAlphabet] = false;
					visited[next.row][next.col] = false;
				}
			}
		}
	}
}
