// Baekjoon04963_NumberOfIslands.cpp
// https://www.acmicpc.net/problem/4963
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( int row, int col ): row(row), col(col) { }
};

void BFS( Position curr, int map[][50], bool visited[][50], int w, int h );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int w, h;
	cin >> w >> h;

	while ( w || h ) {
		int map[50][50];
		for ( int i = 0; i < h; i++ )
			for ( int j = 0; j < w; j++ )
				cin >> map[i][j];

		int count = 0;
		bool visited[50][50] = { false, };
		for ( int i = 0; i < h; i++ ) {
			for ( int j = 0; j < w; j++ ) {
				if ( !visited[i][j] ) {
					visited[i][j] = true;
					if ( map[i][j] == 1 ) {
						BFS( Position( i, j ), map, visited, w, h );

						count++;
					}
				}
			}
		}

		cout << count << '\n';

		cin >> w >> h;
	}

	return 0;
}

void BFS( Position curr, int map[][50], bool visited[][50], int w, int h ) {
	queue<Position> q;
	q.push( curr );

	while ( !q.empty() ) {
		Position curr = q.front(); q.pop();

		Position nextPoints[8] = {
			Position( curr.row - 1, curr.col - 1 ),
			Position( curr.row - 1, curr.col ),
			Position( curr.row - 1, curr.col + 1 ),
			Position( curr.row, curr.col - 1 ),
			Position( curr.row, curr.col + 1 ),
			Position( curr.row + 1, curr.col - 1 ),
			Position( curr.row + 1, curr.col ),
			Position( curr.row + 1, curr.col + 1 )
		};

		for ( Position& pos : nextPoints ) {
			if ( 0 <= pos.row && pos.row < h && 0 <= pos.col && pos.col < w ) {
				if ( !visited[pos.row][pos.col] && map[pos.row][pos.col] == 1 ) {
					visited[pos.row][pos.col] = true;
					q.push( pos );
				}
			}
		}
	}
}