// Baekjoon01238_Party.cpp
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int v, w;
	Node() {}
	Node( int vertex, int weight ): v(vertex), w(weight) {}
};

struct compare {
	bool operator() ( const Node& n1, const Node& n2 ) const {
		return n1.w > n2.w;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	vector<Node> adjList[1001];
	for ( int i = 0; i < m; i++ ) {
		int u, v, w;
		cin >> u >> v >> w;
		adjList[u].push_back( Node( v, w ) );
	}

	int shortest[1001];
	for ( int i = 1; i <= n; i++ ) {
		priority_queue<Node, vector<Node>, compare> pq;
		bool visited[1001] = { false, };

		Node curr;
		pq.push( Node( i, 0 ) );
		while ( !pq.empty() && (curr = pq.top()).v != x ) {
			pq.pop();
			if ( !visited[curr.v] ) {
				visited[curr.v] = true;
				for ( int i = 0; i < adjList[curr.v].size(); i++ ) {
					Node adjNode = adjList[curr.v][i];
					if ( !visited[adjNode.v] )
						pq.push( Node( adjNode.v, adjNode.w + curr.w ) );
				}
			}
		}

		shortest[i] = curr.w;
	}

	int maxVal = 0;
	priority_queue<Node, vector<Node>, compare> pq;
	bool visited[1001] = { false, };

	pq.push( Node( x, 0 ) );
	while ( !pq.empty() ) {
		Node curr = pq.top(); pq.pop();
		if ( !visited[curr.v] ) {
			shortest[curr.v] += curr.w;
			maxVal = ( maxVal < shortest[curr.v] ) ? shortest[curr.v] : maxVal;
			visited[curr.v] = true;
			for ( int i = 0; i < adjList[curr.v].size(); i++ ) {
				Node adjNode = adjList[curr.v][i];
				if ( !visited[adjNode.v] )
					pq.push( Node( adjNode.v, curr.w + adjNode.w ) );
			}
		}
	}

	cout << maxVal << '\n';

	return 0;
}