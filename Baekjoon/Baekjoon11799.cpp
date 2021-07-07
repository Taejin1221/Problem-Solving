// Baekjoon11799_LeastExpense.cpp
// https://www.acmicpc.net/problem/11779
#include <iostream>
#include <queue>
#include <vector>

#define endl '\n';
#define MAX 1'001

using namespace std;

struct Vertex {
	int adj, weight;
	Vertex(): adj(0), weight(0) { }
	Vertex( int a, int w ): adj(a), weight(w) { }
};

struct Node {
	int prev, curr, weight;
	Node(): prev(0), curr(0), weight(0) { }
	Node( int p, int c, int w ): prev(p), curr(c), weight(w) { }
	bool operator<( const Node& n2 ) const {
		return weight > n2.weight;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Vertex> adjList[MAX];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back( Vertex( b ,c ) );
	}

	int start, end;
	cin >> start >> end;

	int path[MAX], minCost = 0;
	bool visited[MAX] = { false, };
	priority_queue<Node> pq;

	pq.push( Node( 0, start, 0 ) );
	while ( !pq.empty() ) {
		Node currNode = pq.top(); pq.pop();

		if ( !visited[currNode.curr] ) {
			visited[currNode.curr] = true;

			path[currNode.curr] = currNode.prev;
			if ( currNode.curr == end ) {
				minCost = currNode.weight;
				break;
			}

			for ( Vertex& next : adjList[currNode.curr] ) {
				int nextNode = next.adj;
				if ( !visited[nextNode] ) {
					pq.push( Node( currNode.curr, nextNode, currNode.weight + next.weight ) );
				}
			}
		}
	}

	int cityNum = 1;
	vector<int> visitCity;

	int curr = end;
	visitCity.push_back( curr );
	while ( curr != start) {
		visitCity.push_back( path[curr] );
		curr = path[curr];
		cityNum++;
	}

	cout << minCost << endl;
	cout << cityNum << endl;
	for ( int i = visitCity.size() - 1; i >= 0; i-- )
		cout << visitCity[i] << ' ';
	cout << endl;

	return 0;
}
