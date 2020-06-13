// Baekjoon02636_Cheese.cpp
// https://www.acmicpc.net/problem/2636
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position(int y, int x): row(y), col(x) {};
};

int n, m;
int matrix[100][100];
int visited[100][100];

void bfs( Position start, int val );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int time = 0;
	int count1 = 0;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			cin >> matrix[i][j];
			if ( matrix[i][j] == 1 )
				count1++;
		}
	}

	if ( !count1 ) {
		cout << "0\n0\n";
		return 0;
	}

	bfs( Position( 0, 0 ), 2 );
	while ( true ) {
		int currTime = time + 2, futureTime = time + 3;
		int edge = 0;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < m; j++ ) {
				if ( matrix[i][j] == 1 ) {
					Position surr[4] = {
						Position( i - 1, j ),
						Position( i, j - 1 ),
						Position( i, j + 1 ),
						Position( i + 1, j)
					};
					for ( int idx = 0; idx < 4; idx++ ) {
						Position next = surr[idx];
						if ( matrix[next.row][next.col] == currTime ) {
							visited[i][j] = true;
							matrix[i][j] = futureTime;
							edge++;
							break;
						}
					}

					if ( matrix[i][j] == futureTime ) {
						for ( int idx = 0; idx < 4; idx++ ) {
							Position next = surr[idx];
							if ( !matrix[next.row][next.col] ) {
								bfs( next, futureTime );
								break;
							}
						}
					}
				}
			}
		}
		time++;
		count1 -= edge;
		if ( count1 <= 0 ) {
			cout << time << '\n' << edge << '\n';
			break;
		}
	}

	return 0;
}

void bfs( Position start, int val ) {
	queue<Position> q;

	visited[start.row][start.col] = true;
	q.push( start );
	while ( !q.empty() ) {
		Position curr = q.front(); q.pop();
		matrix[curr.row][curr.col] = val;

		Position surr[4] = {
			Position( curr.row - 1, curr.col ),
			Position( curr.row, curr.col - 1 ),
			Position( curr.row, curr.col + 1 ),
			Position( curr.row + 1, curr.col)
		};
		for ( int i = 0; i < 4; i++ ) {
			Position next = surr[i];
			if ( 0 <= next.row && next.row < n && 0 <= next.col && next.col < m ) {
				if ( !visited[next.row][next.col] && !matrix[next.row][next.col] ) {
					visited[next.row][next.col] = true;
					q.push( Position( next.row, next.col ) );
				}
			}
		}
	}
}