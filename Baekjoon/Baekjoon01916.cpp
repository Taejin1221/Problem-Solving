// Baekjoon01916_LeastExpense.cpp
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int vertex, weight;
	Node( int v, int w ): vertex(v), weight(w) {}
};

struct compare {
	bool operator() (const Node& n1, const Node& n2 ) const {
		if ( n1.weight != n2.weight )
			return n1.weight > n2.weight;
		else
			return n1.vertex > n2.vertex;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cityNum, busNum;
	cin >> cityNum >> busNum;

	vector<Node> adjList[1001];
	for ( int i = 0; i < busNum; i++ ) {
		int s, e, w;
		cin >> s >> e >> w;

		adjList[s].push_back( Node( e, w ) );
	}

	int start, end;
	cin >> start >> end;

	bool visited[1001] = { false, };
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push( Node( start, 0 ) );
	while ( !pq.empty() ) {
		Node currNode = pq.top(); pq.pop();

		int currVertex = currNode.vertex;
		int currWeight = currNode.weight;
		if ( currVertex == end ) {
			cout << currWeight << '\n';
			break;
		}
		if ( !visited[currVertex] ) {
			visited[currVertex] = true;
			for ( int i = 0; i < adjList[currVertex].size(); i++ ) {
				Node adjVertex = adjList[currVertex][i];
				if ( !visited[adjVertex.vertex] )
					pq.push( Node( adjVertex.vertex, adjVertex.weight + currWeight ) );
			}
		}
	}

	return 0;
}