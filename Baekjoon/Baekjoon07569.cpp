// Baekjoon07569_Tomato.cpp
// https://www.acmicpc.net/problem/7569
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Position {
	int layer, row, col;
	Position( int x, int y, int z ): layer(x), row(y), col(z) {};
};

int main(void) {
	int h, n, m;
	scanf("%d %d %d", &m, &n, &h);

	int repeat = 0, zeros = 0;
	vector<Position> v;
	int tomatoes[100][100][100];
	for ( int i = 0; i < h; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			for ( int k = 0; k < m; k++ ) {
				scanf("%d", &tomatoes[i][j][k]);
				if ( tomatoes[i][j][k] == 1 ) {
					v.push_back( Position( i, j, k ) );
					repeat++;
				} else if ( tomatoes[i][j][k] == 0 )
					zeros++;
			}
		}
	}

	queue<Position> q;
	for ( int i = 0; i < (int)v.size(); i++ )
		q.push( v[i] );

	int count = -1;
	while ( !q.empty() ) {
		int tempRepeat = 0;
		while ( repeat-- ) {
			Position curr = q.front(); q.pop();

			Position surr[6] = {
				{ curr.layer - 1, curr.row, curr.col },
				{ curr.layer, curr.row - 1, curr.col },
				{ curr.layer, curr.row, curr.col - 1 },
				{ curr.layer, curr.row, curr.col + 1 },
				{ curr.layer, curr.row + 1, curr.col },
				{ curr.layer +1, curr.row, curr.col }
			};

			for ( int i = 0; i < 6; i++ ) {
				Position next = surr[i];
				if ( 0 <= next.layer && next.layer < h &&
					0 <= next.row && next.row < n &&
					0 <= next.col && next.col < m ) {
					if ( tomatoes[next.layer][next.row][next.col] == 0 ) {
						zeros--;
						tomatoes[next.layer][next.row][next.col] = 1;
						q.push( Position( next.layer, next.row, next.col ) );
						tempRepeat++;
					}
				}
			}
		}
		count++;
		repeat = tempRepeat;
	}

	printf("%d\n", zeros ? -1 : count);

	return 0;
}