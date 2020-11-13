// Baekjoon07562_KnightMove.cpp
// https://www.acmicpc.net/problem/7562
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( ): row(0), col(0) { }
	Position( int r, int c ): row(r), col(c) { }
	bool operator==( Position& pos2 ) {
		return ( row == pos2.row && col == pos2.col );
	}
};

struct Node {
	 Position pos;
	 int time;
	 Node( Position p, int t ): pos(p), time(t) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;

		bool board[300][300] = { false, };

		Position start, end;
		cin >> start.row >> start.col;
		cin >> end.row >> end.col;

		queue<Node> q;
		q.push( Node( start, 0 ) );

		while ( !q.empty() ) {
			Node curr = q.front(); q.pop();

			if ( curr.pos == end ) {
				cout << curr.time << '\n';
				break;
			}

			Position nextMove[8] = {
				Position( curr.pos.row - 1, curr.pos.col - 2 ),
				Position( curr.pos.row - 2, curr.pos.col - 1 ),
				Position( curr.pos.row - 2, curr.pos.col + 1 ),
				Position( curr.pos.row - 1, curr.pos.col + 2),
				Position( curr.pos.row + 1, curr.pos.col + 2 ),
				Position( curr.pos.row + 2, curr.pos.col + 1 ),
				Position( curr.pos.row + 2, curr.pos.col - 1 ),
				Position( curr.pos.row + 1, curr.pos.col - 2 )
			};

			for ( Position& next : nextMove ) {
				if ( ( 0 <= next.row && next.row < n ) && ( 0 <= next.col && next.col < n ) ) {
					if ( !board[next.row][next.col] ) {
						board[next.row][next.col] = true;
						q.push( Node( next, curr.time + 1 ) );
					}
				}
			}
		}
	}

	return 0;
}