// Baekjoon01261_Algospot.cpp
// https://www.acmicpc.net/problem/1261
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int r, c;
	Position() {}
	Position( int row, int col ): r(row), c(col) {}
};

struct Node {
	Position pos;
	int w;
	Node() {}
	Node( Position pos1, int wall ): pos(pos1), w(wall) {}
};

struct compare {
	bool operator()( const Node& n1, const Node& n2 ) const {
		if ( n1.w != n2.w )
			return n1.w > n2.w;
		else if ( n1.pos.r != n2.pos.r )
			return n1.pos.r > n2.pos.r;
		else
			return n1.pos.c > n2.pos.c;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> m >> n;

	char maze[100][100];
	for ( int i = 0; i < n; i++ )
		cin >> maze[i];

	bool visited[100][100] = { false, };
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push( Node( Position( 0, 0 ), 0 ) );
	while ( !pq.empty() ) {
		Node currNode = pq.top(); pq.pop();
		Position currPos = currNode.pos;

		if ( (currPos.r == n - 1) && (currPos.c == m - 1) ) {
			cout << currNode.w << '\n';
			break;
		}

		if ( !visited[currPos.r][currPos.c] ) {
			visited[currPos.r][currPos.c] = true;
			Position surr[4] = {
				Position( currPos.r - 1, currPos.c ),
				Position( currPos.r, currPos.c + 1 ),
				Position( currPos.r + 1, currPos.c ),
				Position( currPos.r, currPos.c - 1 )
			};
			for ( int i = 0; i < 4; i++ ) {
				Position next = surr[i];
				if ( (0 <= next.r && next.r < n) && (0 <= next.c && next.c < m) )
					if ( !visited[next.r][next.c] ) {
						int nextWall = currNode.w + (maze[next.r][next.c] - '0');
						pq.push( Node( next, nextWall ) );
					}
			}
		}
	}

	return 0;
}