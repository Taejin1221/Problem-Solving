// Baekjoon04485_ObstacleCourse.cpp
// https://www.acmicpc.net/problem/4485
#include <iostream>
#include <queue>

using namespace std;

struct Position {
	int r, c;
	Position( int row, int col ): r(row), c(col) {}
};

struct Node {
	Position p;
	int w;
	Node( Position pos, int weight ): p(pos), w(weight) {}
};

struct compare {
	bool operator() ( const Node& n1, const Node& n2 ) const {
		if ( n1.w != n2.w )	return n1.w > n2.w;
		else if ( n1.p.r != n2.p.r ) return n1.p.r > n2.p.r;
		else return n1.p.c > n2.p.c;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	for ( int time = 1; n; time++ ) {
		int cave[125][125];
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				cin >> cave[i][j];

		bool visited[125][125] = { false, };
		priority_queue<Node, vector<Node>, compare> pq;

		pq.push( Node( Position( 0, 0 ), cave[0][0] ) );
		while ( !pq.empty() ) {
			Node currNode = pq.top(); pq.pop();

			if ( ( currNode.p.r == n - 1 ) && ( currNode.p.c == n - 1 ) ) {
				cout << "Problem " << time << ": " << currNode.w << '\n';
				break;
			}
			if ( !visited[currNode.p.r][currNode.p.c] ) {
				visited[currNode.p.r][currNode.p.c] = true;
				Position surr[4] = {
					Position( currNode.p.r - 1, currNode.p.c ),
					Position( currNode.p.r, currNode.p.c + 1 ),
					Position( currNode.p.r + 1, currNode.p.c ),
					Position( currNode.p.r, currNode.p.c - 1 )
				};
				for ( auto next : surr ) {
					if ( (0 <= next.r && next.r < n) && (0 <= next.c && next.c < n) )
						if ( !visited[next.r][next.c] )
							pq.push( Node( next, currNode.w + cave[next.r][next.c] ) );
				}
			}
		}

		cin >> n;
	}

	return 0;
}