	// Baekjoon11909_EscapeArray.cpp
	// https://www.acmicpc.net/problem/11909
	#include <iostream>
	#include <queue>

	#define MAX_ARR_SIZE 2222

	using namespace std;

	struct Node {
		int row, col;
		int cost;
		Node( ): row(0), col(0), cost(0) { }
		Node( int r, int c, int cost ): row(r), col(c), cost(cost) { }
		bool operator<( const Node& n2 ) const {
			return cost > n2.cost;
		}
	};

	int main(void) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n;
		cin >> n;

		int mat[MAX_ARR_SIZE][MAX_ARR_SIZE];
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				cin >> mat[i][j];

		bool visited[MAX_ARR_SIZE][MAX_ARR_SIZE] = { false, };
		priority_queue<Node> pq;

		int ans;
		pq.push( Node( 0, 0, 0 ) );
		while ( !pq.empty() ) {
			Node curr = pq.top(); pq.pop();

			if ( curr.row == n - 1 && curr.col == n - 1 ) {
				ans = curr.cost;
				break;
			}

			if ( !visited[curr.row][curr.col] ) {
				visited[curr.row][curr.col] = true;
				int element = mat[curr.row][curr.col];

				Node nextNode[2] = {
					Node( curr.row, curr.col + 1, curr.cost ),
					Node( curr.row + 1, curr.col, curr.cost )
				};

				for ( Node& next : nextNode ) {
					if ( (0 <= next.row && next.row < n) && (0 <= next.col && next.col < n)) {
						if ( !visited[next.row][next.col] ) {
							if ( element <= mat[next.row][next.col] )
								next.cost += ( mat[next.row][next.col] - element + 1 );
							pq.push( next );
						}
					}
				}
			}
		}

		cout << ans << '\n';

		return 0;
	}