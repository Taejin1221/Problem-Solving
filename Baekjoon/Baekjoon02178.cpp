// Baekjoon02178_MazeSearch.cpp
// https://www.acmicpc.net/problem/2178
#include <cstdio>
#include <queue>

using namespace std;

struct Position {
	int row, col;
};

struct Node {
	Position pos;
	int count;
};

int main(void) {
	char maze[100][100];
	bool visited[100][100] = { { false, } };

	int n, m;
	scanf( "%d %d", &n, &m );

	for ( int i = 0; i < n; i++ )
		scanf( "%s", maze[i] );

	queue<Node> q;

	visited[0][0] = true;
	q.push( { { 0, 0 }, 1 } );
	while ( !q.empty() ) {
		Node currNode = q.front(); q.pop();

		Position currPos = currNode.pos;
		if ( currPos.row == n - 1 && currPos.col == m - 1 ) {
			printf("%d\n", currNode.count );
			break;
		}

		Position surr[4] = {
			{ currPos.row - 1, currPos.col },
			{ currPos.row, currPos.col - 1 },
			{ currPos.row, currPos.col + 1 },
			{ currPos.row + 1, currPos.col }
		};

		for ( int i = 0; i < 4; i++ ) {
			Position next = surr[i];
			if ( 0 <= next.row && next.row < n && 0 <= next.col && next.col < m ) {
				if ( maze[next.row][next.col] - '0' && !visited[next.row][next.col] ) {
					visited[next.row][next.col] = true;
					q.push( { next, currNode.count + 1 } );
				}
			}
		}
	}

	return 0;
}
