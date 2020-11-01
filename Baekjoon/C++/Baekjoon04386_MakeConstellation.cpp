// Baekjoon04386_MakeConstellation.cpp
// https://www.acmicpc.net/problem/4386
#include <cstdio>
#include <cmath>
#include <queue> /* priority_queue */

using namespace std;

struct Coordinate {
	double x, y;
	Coordinate() : x(0.0), y(0.0) { }
	Coordinate( double x, double y ): x(x), y(y) { }
	double getDistance( const Coordinate& target ) const {
		double xDist = x - target.x,
			yDist = y - target.y;

		return sqrt( xDist * xDist + yDist * yDist );
	}
};

struct Node {
	int star;
	double weight;
	Node( int s, double w ): star(s), weight(w) { }
	bool operator<( const Node& n2 ) const {
		return weight > n2.weight;
	}
};

int main(void) {
	int n;
	scanf("%d", &n);

	Coordinate stars[100];
	for ( int i = 0; i < n; i++ )
		scanf("%lf %lf", &stars[i].x, &stars[i].y);

	double sum = 0.0;

	bool visited[100] = { false, };
	priority_queue<Node> pq;
	pq.push( Node( 0, 0.0 ) );
	while ( !pq.empty() ) {
		Node curr = pq.top(); pq.pop();

		if ( !visited[curr.star] ) {
			visited[curr.star] = true;
			sum += curr.weight;
			for ( int i = 0; i < n; i++ ) {
				if ( !visited[i] )
					pq.push( Node( i, stars[curr.star].getDistance( stars[i] ) ) );
			}
		}
	}

	printf("%.2f\n", sum);

	return 0;
}
