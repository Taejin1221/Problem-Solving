// Baekjoon01753_ShortestPath.cpp
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int vertex;
	int weight;
	Node( int v, int w ): vertex(v), weight(w) {}
};

struct Compare {
	bool operator()( const Node& n1, const Node& n2 ) const {
		if ( n1.weight != n2.weight )
			return n1.weight > n2.weight;
		else
			return n1.vertex > n2.vertex;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	int start;
	cin >> start;

	vector<Node> adjList[20001];
	for ( int i = 0; i < E; i++ ) {
		int u, v, w;
		cin >> u >> v >> w;

		adjList[u].push_back( Node( v, w ) );
	}

	bool visited[20001] = { false, };

	int shortest[20001];
	for ( int i = 1; i <= V; i++ )
		shortest[i] = -1;
	shortest[start] = 0;

	priority_queue<Node, vector<Node>, Compare> pq;
	pq.push( Node( start, 0 ) );
	while ( !pq.empty() ) {
		Node currNode = pq.top(); pq.pop();

		int currVertex = currNode.vertex, currWeight = currNode.weight;
		if ( !visited[currVertex] ) {
			visited[currVertex] = true;
			shortest[currVertex] = currWeight;
			for ( int i = 0; i < adjList[currVertex].size(); i++ ) {
				int adjVertex = adjList[currVertex][i].vertex, adjWeight = adjList[currVertex][i].weight;
				if ( !visited[adjVertex] )
					pq.push( Node( adjVertex, adjWeight + currWeight ) );
			}
		}
	}

	for ( int i = 1; i <= V; i++ ) {
		if ( shortest[i] != -1 )
			cout << shortest[i] << '\n';
		else
			cout << "INF\n";
	}

	return 0;
}