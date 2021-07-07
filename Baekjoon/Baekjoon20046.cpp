// Baekjoon20046_RoadReconstruction.cpp
// https://www.acmicpc.net/problem/20046
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int row, col;
	int cost;
	Node( ): row(0), col(0), cost(0) {}
	Node( int r, int c, int cost ): row(r), col(c), cost(cost) {}
	bool operator<( const Node& n2 ) const {
		return cost > n2.cost;
	}
};

int main(void) {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);

	int row, col;
	cin >> row >> col;

	int roads[1000][1000];
	for ( int i = 0; i < row; i++ )
		for ( int j = 0; j < col; j++ )
			cin >> roads[i][j];

	if ( roads[0][0] == -1 || roads[row - 1][col - 1] == -1 )
		cout << -1;
	else {
		priority_queue<Node> pq;
		pq.push( Node( 0, 0, roads[0][0] ) );

		int ans = - 1;
		bool visited[1000][1000] = { 0, };
		while ( !pq.empty() ) {
			Node curr = pq.top(); pq.pop();
			if ( !visited[curr.row][curr.col] ) {
				visited[curr.row][curr.col] = true;

				if ( curr.row == row - 1 && curr.col == col - 1 ) {
					ans = curr.cost;
					break;
				}

				Node nexts[4] = { 
					Node( curr.row - 1, curr.col, 0 ),
					Node( curr.row, curr.col + 1, 0 ),
					Node( curr.row + 1, curr.col, 0 ),
					Node( curr.row, curr.col - 1, 0 )
				};

				for( Node& next : nexts ) {
					if ( (0 <= next.row && next.row < row) &&  (0 <= next.col && next.col < col) ) {
						if ( !visited[next.row][next.col] && roads[next.row][next.col] != -1 ) {
							next.cost = curr.cost + roads[next.row][next.col];
							pq.push( next );
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
