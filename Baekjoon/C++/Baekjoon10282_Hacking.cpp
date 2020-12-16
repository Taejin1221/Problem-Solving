// Baekjoon10282_Hacking.cpp
// https://www.acmicpc.net/problem/10282
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int vertex, weight;
	Node( int v, int w ): vertex(v), weight(w) { }
	bool operator<( const Node& n2 ) const {
		return weight > n2.weight;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		int n, d, c;
		cin >> n >> d >> c;

		vector<Node> adjList[10'001];
		for ( int i = 0; i < d; i++ ) {
			int a, b, s;
			cin >> a >> b >> s;

			adjList[b].push_back( Node( a, s ) );
		}

		int hackCom = 0, hackTime = 0;

		bool visited[10'001] = { false, };

		priority_queue<Node> pq;
		pq.push( Node( c, 0 ) );
		while ( !pq.empty() ) {
			Node curr = pq.top(); pq.pop();

			if ( !visited[curr.vertex] ) {
				visited[curr.vertex] = true;
				hackCom++;
				hackTime = curr.weight;

				for ( Node& adj : adjList[curr.vertex] ) {
					if ( !visited[adj.vertex] )
						pq.push( Node( adj.vertex, curr.weight + adj.weight ) );
				}
			}
		}

		cout << hackCom << ' ' << hackTime << '\n';
	}

	return 0;
}
