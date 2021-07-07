// Baekjoon09205_Kastenlauf.cpp
// https://www.acmicpc.net/problem/9205
#include <iostream>
#include <queue>

#define abs( a ) (( ( a ) > 0 ) ? ( a ) : ( -(a) ))

using namespace std;

struct Coords {
	int x, y;
	Coords( ): x(0), y(0) {}
	Coords( int x, int y ): x(x), y(y) {}
	bool operator==( const Coords& c2 ) {
		return ( x == c2.x && y == c2.y );
	}

	int getDis( const Coords& c2 ) {
		return ( abs( x - c2.x ) + abs( y - c2.y ) );
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		Coords coords[102];
		for ( int i = 0; i <= n + 1; i++ )
			cin >> coords[i].x >> coords[i].y;
		Coords& end = coords[n + 1];

		queue<Coords> q;
		bool isHappy = false, visited[102] = { false, };
		q.push( coords[0] ); visited[0] = true;
		while ( !q.empty() ) {
			Coords curr = q.front(); q.pop();
			if ( curr == end )
				isHappy = true;
			else {
				for ( int i = 1; i <= n + 1; i++ ) {
					if ( !visited[i] && curr.getDis( coords[i] ) <= 1000 ) {
						visited[i] = true;
						q.push( coords[i] );
					}
				}
			}
		}

		if ( isHappy )
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}