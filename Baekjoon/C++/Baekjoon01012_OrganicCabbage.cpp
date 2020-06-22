// Baekjoon01012_OrganicCabbage.cpp
// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( int y, int x ): row(y), col(x) {};
};

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int worm = 0;

		int n, m, k;
		cin >> m >> n >> k;

		bool field[50][50] = { { false, } };
		bool visited[50][50] = { { false, } };

		while ( k-- ) {
			int x, y;
			cin >> x >> y;
			field[y][x] = true;
		}

		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				if ( !visited[i][j] && field[i][j] ) {
					visited[i][j] = true;

					queue<Position> q;
					q.push( Position( i, j ) );
					while ( !q.empty() ) {
						Position curr = q.front(); q.pop();

						Position surr[4] = {
							Position( curr.row - 1, curr.col ),
							Position( curr.row, curr.col - 1 ),
							Position( curr.row, curr.col + 1 ),
							Position( curr.row + 1, curr.col )
						};
						for ( int i = 0; i < 4; i++ ) {
							int nextRow = surr[i].row, nextCol = surr[i].col;
							if ( 0 <= nextRow && nextRow < n &&
								0 <= nextCol && nextCol < m ) {
								if ( !visited[nextRow][nextCol] && field[nextRow][nextCol] ) {
									visited[nextRow][nextCol] = true;
									q.push( Position( nextRow, nextCol ) );
								}
							}
						}
					}

					worm++;
				}
			}
		}

		cout << worm << '\n';
	}

	return 0;
}