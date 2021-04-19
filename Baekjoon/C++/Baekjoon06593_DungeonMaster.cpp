// Baekjoon06593_DungeonMaster.cpp
// https://www.acmicpc.net/problem/6593
#include <iostream>

#include <queue>

using namespace std;

struct Position {
	int layer, row, col, time;
	Position( ): layer( 0 ), row( 0 ), col( 0 ), time( 0 ) { }
	Position( int l, int r, int c ): layer( l ), row( r ), col( c ), time( 0 ) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int l, r, c;
	cin >> l >> r >> c;
	while ( !(l == 0 && r == 0 && c == 0) ) {
		char building[30][30][31];
		for ( int i = 0; i < l; i++ )
			for ( int j = 0; j < r; j++ )
				cin >> building[i][j];

		Position start;
		for ( int i = 0; i < l; i++ )
			for ( int j = 0; j < r; j++ )
				for ( int k = 0; k < c; k++ )
					if ( building[i][j][k] == 'S' )
						start = Position( i, j, k );

		queue<Position> q;
		bool visited[30][30][30] = { false, };

		bool isEscape = false;

		q.push( start );
		visited[start.layer][start.row][start.col] = true;

		int ans;
		while ( !q.empty() ) {
			Position curr = q.front(); q.pop();
			if ( building[curr.layer][curr.row][curr.col] == 'E' ) {
				isEscape = true;
				ans = curr.time;
				break;
			}

			Position nexts[6] = {
				Position( curr.layer + 1, curr.row, curr.col ),
				Position( curr.layer - 1, curr.row, curr.col ),
				Position( curr.layer, curr.row + 1, curr.col ),
				Position( curr.layer, curr.row - 1, curr.col ),
				Position( curr.layer, curr.row, curr.col + 1 ),
				Position( curr.layer, curr.row, curr.col - 1 )
			};

			for ( Position next : nexts ) {
				next.time = curr.time + 1;
				int layer = next.layer, row = next.row, col = next.col;
				if ( ( 0 <= layer && layer < l ) && ( 0 <= row && row < r ) && ( 0 <= col && col < c ) ) {
					if ( building[layer][row][col] != '#' && !visited[layer][row][col] ) {
						visited[layer][row][col] = true;
						q.push( next );
					}
				}
			}
		}

		if ( isEscape )
			cout << "Escaped in " << ans << " minute(s).";
		else
			cout << "Trapped!";
		cout << '\n';

		cin >> l >> r >> c;
	}

	return 0;
}