// Baekjoon01167_DiameterOfTree.cpp
// https://www.acmicpc.net/problem/1167
#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int node, weight;
	Node(int n, int w): node(n), weight(w) {}
};

int diameter, farNode;
vector<Node> adjList[100'001];

void dfs( int me, int mom, int curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		int curr; cin >> curr;

		int node, weight;
		cin >> node;
		while ( node != -1 ) {
			cin >> weight;

			adjList[curr].push_back( Node( node, weight ) );

			cin >> node;
		}
	}

	dfs( 1, 0, 0 );
	dfs( farNode, 0, 0 );

	cout << diameter << '\n';

	return 0;
}

void dfs( int me, int mom, int curr ) {
	if ( curr > diameter ) {
		diameter = curr;
		farNode = me;
	}

	for ( Node& son : adjList[me] )
		if ( son.node != mom )
			dfs( son.node, me, curr + son.weight );
}