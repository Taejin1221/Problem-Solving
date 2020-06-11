// Baekjoon02206_BreakandMoveWall.cpp
// https://www.acmicpc.net/problem/2206
#include <cstdio>
#include <queue>

#define MAX_SIZE 1000

using namespace std;

struct Position {
	int r, c;
};

struct Node {
	Position pos;
	int count;
	bool breaked;

	Node(int row, int col, int cnt, bool flag): pos({row, col}), count(cnt), breaked(flag) {};
};

int main(void) {
	char matrix[MAX_SIZE][MAX_SIZE];
	bool visited[2][MAX_SIZE][MAX_SIZE] = { { { false, } } };

	visited[0][0][0] = visited[1][0][0] = true;

	int n, m;
	scanf( "%d %d", &n, &m );
	for ( int i = 0; i < n; i++ )
		scanf( "%s", matrix[i] );

	queue<Node> q;
	q.push( Node(0, 0, 1, false) );
	while( !q.empty() ) {
		Node curr = q.front(); q.pop();

		Position currPos = curr.pos;
		if ( currPos.r == ( n - 1 ) && currPos.c == ( m - 1 ) ) {
			printf("%d\n", curr.count );
			return 0;
		}

		Position surr[4] = {
			{ currPos.r - 1, currPos.c },
			{ currPos.r, currPos.c - 1 },
			{ currPos.r, currPos.c + 1 },
			{ currPos.r + 1, currPos.c }
		};
		for ( int i = 0; i < 4; i++ ) {
			Position next = surr[i];
			if ( (0 <= next.r && next.r < n) && (0 <= next.c && next.c < m) ) {
				if ( matrix[next.r][next.c] == '1') {
					if ( !curr.breaked ) {
						if ( !visited[1][next.r][next.c] ) {
							visited[1][next.r][next.c] = true;
							q.push( Node( next.r, next.c, curr.count + 1, true ) );
						}
					}
				} else {
					if ( curr.breaked ) {
						if ( !visited[1][next.r][next.c] ) {
							visited[1][next.r][next.c] = true;
							q.push( Node( next.r, next.c, curr.count + 1, curr.breaked ) );
						}
					} else {
						if ( !visited[0][next.r][next.c] ) {
							visited[0][next.r][next.c] = true;
							q.push( Node( next.r, next.c, curr.count + 1, curr.breaked ) );
						}
					}
				}
			}
		}
	}

	puts("-1");

	return 0;
}