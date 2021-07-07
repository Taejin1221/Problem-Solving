// Baekjoon01922_ConnectNetwork.cpp
// https://www.acmicpc.net/problem/1922
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Vertex {
	int adjVertex, cost;
	Vertex( int a, int c ): adjVertex(a), cost(c) { }
};

struct Node {
	int vertex, cost;
	Node( int v, int c ): vertex(v), cost(c) { }
	bool operator<( const Node& n2 ) const {
		return cost > n2.cost;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Vertex> adjList[1001];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back( Vertex( b, c ) );
		adjList[b].push_back( Vertex( a, c ) );
	}

	bool visited[1001] = { false, };
	priority_queue<Node> pq;

	int visitVertex = 0, ans = 0;
	pq.push( Node( 1, 0 ) );
	while ( !pq.empty() && visitVertex < n ) {
		Node curr = pq.top(); pq.pop();

		if ( !visited[curr.vertex] ) {
			visited[curr.vertex] = true;
			visitVertex++;
			ans += curr.cost;

			for ( Vertex& next : adjList[curr.vertex] )
				if ( !visited[next.adjVertex] )
					pq.push( Node( next.adjVertex, next.cost ) );
		}
	}

	cout << ans << '\n';

	return 0;
}
