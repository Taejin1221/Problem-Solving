// Baekjoon02665_MakeMaze.cpp
// https://www.acmicpc.net/problem/2665
#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int row, col;
	int cost;
	Node(int r, int c, int cost): row(r), col(c), cost(cost) {}
	bool operator<(const Node& node2) const {
		return cost > node2.cost;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char maze[50][50];
	for ( int i = 0; i < n; i++ )
		cin >> maze[i];

	int ans = 0;
	priority_queue<Node> pq;
	bool visited[50][50] = { false, };

	pq.push( Node( 0, 0, 0 ) );
	while ( !pq.empty() ) {
		Node curr = pq.top(); pq.pop();
		if ( !visited[curr.row][curr.col] ) {
			visited[curr.row][curr.col] = true;

			if ( curr.row == n - 1 && curr.col == n - 1 ) {
				ans = curr.cost;
				break;
			}

			Node nexts[4] = {
				Node( curr.row - 1, curr.col, curr.cost ),
				Node( curr.row, curr.col + 1, curr.cost ),
				Node( curr.row + 1, curr.col, curr.cost ),
				Node( curr.row, curr.col - 1, curr.cost )
			};

			for ( Node& next : nexts ) {
				if ( ( 0 <= next.row && next.row < n ) && ( 0 <= next.col && next.col < n ) ) {
					if ( !visited[next.row][next.col] ) {
						if ( maze[next.row][next.col] == '0' )
							next.cost++;
						pq.push( next );
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}