// Baekjoon02583_CalculateDivision.cpp
// https://www.acmicpc.net/problem/2583
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( int x, int y ): row(y), col(x) {};
};

int n, m, k;
bool matrix[100][100];

int bfs( Position start );

int main(void) {
	scanf("%d %d %d", &n, &m, &k);
	
	while ( k-- ) {
		int a,b,c,d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		pair<Position, Position> temp ( Position( a, b ), Position( c, d ) );

		for ( int i = temp.first.row; i < temp.second.row; i++ )
			for ( int j = temp.first.col; j < temp.second.col; j++ )
				matrix[i][j] = true;
	}

	vector<int> v;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			if ( !matrix[i][j] )
				v.push_back(bfs( Position( j, i ) ));

	sort( v.begin(), v.end() );
	printf("%d\n", (int)v.size() );
	for ( int i = 0; i < (int)v.size(); i++ )
		printf("%d ", v[i]);
	puts("");

	return 0;
}

int bfs( Position start ) {
	queue<Position> q;

	int count = 0;
	matrix[start.row][start.col] = true;
	q.push( start );
	while ( !q.empty() ) {
		Position curr = q.front(); q.pop(); count++;

		Position surr[4] = {
			Position( curr.col, curr.row - 1 ),
			Position( curr.col - 1, curr.row ),
			Position( curr.col + 1, curr.row ),
			Position( curr.col, curr.row + 1 )
		};

		for ( int i = 0; i < 4; i++ ) {
			Position next = surr[i];
			if ( 0 <= next.row && next.row < n && 0 <= next.col && next.col < m ) {
				if ( !matrix[next.row][next.col] ) {
					matrix[next.row][next.col] = true;
					q.push( Position( next.col, next.row ) );
				}
			}
		}
	}

	return count;
}