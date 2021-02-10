// Baekjoon16236_BabyShark.cpp
// https://www.acmicpc.net/problem/16236
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int rowChange[4] = { -1, 0, 0, 1 }, colChange[4] = { 0, -1, 1, 0 };

typedef pair<int, int> pii;

struct Node {
	pii pos;
	int time;
	Node( pii p, int t ): pos( p ), time( t ) { }

	bool operator<( const Node& n2 ) const {
		if ( time != n2.time )
			return time > n2.time;
		else {
			if ( pos.first != n2.pos.first )
				return pos.first > n2.pos.first;
			else
				return pos.second > n2.pos.second;
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pii baby;
	int ocean[20][20];
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> ocean[i][j];

			if ( ocean[i][j] == 9 ) {
				baby = { i, j };
				ocean[i][j] = 0;
			}
		}
	}

	int second = 0, sharkSize = 2, fishNum = 0;
	while ( !( baby.first == -1 && baby.second == -1 ) ) {
		priority_queue<Node> pq;
		bool visited[20][20] = { false, };

		pq.push( Node( baby, 0 ) );
		visited[baby.first][baby.second] = true;

		pii nextPos = { -1, -1 };
		while ( !pq.empty() ) {
			Node curr = pq.top(); pq.pop();

			pii currPos = curr.pos;
			int fishPos = ocean[currPos.first][currPos.second]; // fish size on current position
			if ( fishPos != 0 && fishPos < sharkSize ) {
				nextPos = currPos;
				ocean[nextPos.first][nextPos.second] = 0;
				fishNum++;
				second += curr.time;
				break;
			}

			// bfs
			for ( int i = 0; i < 4; i++ ) {
				pii next = { currPos.first + rowChange[i], currPos.second + colChange[i] };
				if ( ( 0 <= next.first && next.first < n ) && ( 0 <= next.second && next.second < n ) ) {
					if ( !visited[next.first][next.second] && ocean[next.first][next.second] <= sharkSize ) {
						visited[next.first][next.second] = true;
						pq.push( Node( next, curr.time + 1 ) );
					}
				}
			}
		}
		
		baby = nextPos;
		if ( fishNum == sharkSize ) {
			sharkSize++;
			fishNum = 0;
		}
	}

	cout << second << '\n';

	return 0;
}