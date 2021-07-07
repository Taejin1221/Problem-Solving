// Baekjoon01504_SpecificShortestPath.cpp
// https://www.acmicpc.net/problem/1504
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int v, w;
	Node() {}
	Node( int vertex, int weight ): v(vertex), w(weight) {}
};

struct compare {
	bool operator()( const Node& n1, const Node& n2 ) const {
		if ( n1.w != n2.w )
			return n1.w > n2.w;
		else
			return n1.v > n2.v;
	}
};

vector<Node> adjList[801];

int Dijkstra( int start, int end );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e;
	cin >> n >> e;

	for ( int i = 0; i < e; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back( Node( b, c ) );
		adjList[b].push_back( Node( a, c ) );
	}

	int target1, target2;
	cin >> target1 >> target2;

	int t1_cost = Dijkstra( 1, target1 ), t2_cost = Dijkstra( 1, target2 );
	int t1_t2 = Dijkstra( target1, target2 );
	int t1_n = Dijkstra( target1, n ), t2_n = Dijkstra( target2, n );

	if ( t1_t2 == -1 )
		cout << -1;
	else if ( t1_cost == -1 ) {
		if ( t1_n == -1 )
			cout << -1;
		else
			cout << t2_cost + t1_t2 + t1_n;
	} else if ( t2_cost == -1 ) {
		if ( t2_n == -1 )
			cout << -1;
		else
			cout << t1_cost + t1_t2 + t2_n;
	} else {
		int totalT1 = t1_cost + t1_t2 + t2_n;
		int totalT2 = t2_cost + t1_t2 + t1_n;
	
		int total = (( totalT1 < totalT2 ) ? totalT1 : totalT2);
		cout << total;
	}

	cout << '\n';

	return 0;
}

int Dijkstra( int start, int end ) {
	bool visited[801] = { false, };
	priority_queue<Node, vector<Node>, compare> pq;

	Node currNode;
	pq.push( Node( start, 0 ) );
	while ( !pq.empty() ) {
		currNode = pq.top(); pq.pop();
		if ( currNode.v == end )
			return currNode.w;

		if ( !visited[currNode.v] ) {
			visited[currNode.v] = true;
			for ( auto adjNode : adjList[currNode.v] ) {
				if ( !visited[adjNode.v] )
					pq.push( Node( adjNode.v, currNode.w + adjNode.w ) );
			}
		}
	}

	return -1;
}