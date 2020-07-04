// Baekjoon01197_MinimumSpanningTree.cpp
// https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector> /* vector<> */
#include <queue> /* priority_queue<> */

using namespace std;

struct Node {
	int v, w;
	Node() {}
	Node( int vertex, int weight ): v(vertex), w(weight) {}
	bool operator <(const Node& n2 ) const {
		if ( w != n2.w )
			return w > n2.w;
		else
			return v > n2.v;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Node> adjList[10001];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back( Node( b, c ) );
		adjList[b].push_back( Node( a, c ) );
	}

	int sum = 0;
	bool visited[10001] = { false, };
	priority_queue<Node> pq; pq.push( Node( 1, 0 ) );
	while ( !pq.empty() ) {
		int currVertex = pq.top().v, currWeight = pq.top().w;
		pq.pop();

		if ( !visited[currVertex] ) {
			sum += currWeight;
			visited[currVertex] = true;
			for ( auto adjNode : adjList[currVertex] )
				if ( !visited[adjNode.v] )
					pq.push( adjNode );
		}
	}

	cout << sum << '\n';

	return 0;
}