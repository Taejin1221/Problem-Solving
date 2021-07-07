// Baekjoon02211_RecoverNetwork.cpp
// https://www.acmicpc.net/problem/2211
#include <iostream>

#include <queue>
#include <vector>

#define end '\n';
#define MAX_SIZE 1'001

using namespace std;

struct Node {
	int start, dest, cost;
	Node( int start, int dest, int cost ): start(start), dest(dest), cost(cost) { }
	bool operator<( const Node& n2 ) const {
		return cost > n2.cost;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Node> adjList[MAX_SIZE];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back( Node( a, b, c ) );
		adjList[b].push_back( Node( b, a, c ) );
	}

	priority_queue<Node> pq;
	bool visited[MAX_SIZE] = { false, };

	vector<Node> path;
	pq.push( Node( 0, 1, 0 ) );
	while ( !pq.empty() ) {
		Node curr = pq.top(); pq.pop();
		if ( !visited[curr.dest] ) {
			visited[curr.dest] = true;
			path.push_back( curr );

			for ( Node& adj : adjList[curr.dest] )
				if ( !visited[adj.dest] )
					pq.push( Node( curr.dest, adj.dest, curr.cost + adj.cost ) );
		}
	}

	cout << path.size() - 1 << endl;
	for ( int i = 1; i < path.size(); i++ )
		cout << path[i].start << ' ' << path[i].dest << endl;

	return 0;
}