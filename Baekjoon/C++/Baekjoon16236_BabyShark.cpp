// Baekjoon16236_BabyShark.cpp
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ABS( x ) (( ( x ) < 0 ) ? ( -(x) ) : x)
using namespace std;

struct Position {
	int row, col;
	Position( ): row(0), col(0) {}
	Position( int r, int c ): row(r), col(c) {}

	int operator-( const Position& p2 ) {
		return ( ABS(row - p2.row) + ABS(col - p2.col) );
	}
};

struct Node {
	Position pos;
	int distance;
	Node( ): pos(), distance(0) {}
	Node( int r, int c, int d ): pos(r, c), distance(d) {}
	Node( Position p, int d ): pos(p), distance(d) {}

	bool operator<( const Node& n2 ) {
		if ( pos.row != n2.pos.row )
			return pos.row < n2.pos.row;
		else
			return pos.col < n2.pos.col;
	}
};

Position shark;
int n, second, sharkSize = 2;
int map[20][20];

Position bfs( Position curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> map[i][j];
			if ( map[i][j] == 9 ) {
				shark.row = i, shark.col = j;
				map[i][j] = 0;
			}
		}
	}

	int fish = 0;
	while ( true ) {
		shark = bfs( shark );
		if ( shark.row == -1 && shark.col == -1 )
			break;
		map[shark.row][shark.col] = 0;

		fish++;
		if ( fish == sharkSize ) {
			fish = 0;
			sharkSize++;
		}
	}

	cout << second << '\n';

	return 0;
}

Position bfs( Position start ) {
	queue<Node> q;
	vector<Node> list;
	bool visited[20][20] = { false, };

	int minDistance = 100;
	q.push( Node( start, 0 ) );
	visited[start.row][start.col] = true;
	while( !q.empty() ) {
		Node currNode = q.front(); q.pop();

		Position currPos = currNode.pos;
		if ( map[currPos.row][currPos.col] && map[currPos.row][currPos.col] < sharkSize ) {
			if ( minDistance < currNode.distance )
				break;
			else {
				minDistance = currNode.distance;
				list.push_back( currNode );
			}
		}

		Position nexts[4] = {
			Position( currPos.row - 1, currPos.col ),
			Position( currPos.row, currPos.col - 1 ),
			Position( currPos.row, currPos.col + 1),
			Position( currPos.row + 1, currPos.col )
		};

		for ( Position& next : nexts ) {
			int row = next.row, col = next.col;
			if ( (0 <= row && row < n) && (0 <= col && col < n) ) {
				if ( !visited[row][col] ) {
					visited[row][col] = true;
					if ( map[row][col] <= sharkSize )
						q.push( Node( row, col , currNode.distance + 1 ) );
				}
			}
		}
	}

	if ( list.size() ) {
		sort( list.begin(), list.end() );
		second += list[0].distance;

		return list[0].pos;
	}
	else
		return Position( -1, -1 );
}