// Baekjoon01967_Diameter.cpp
// https://www.acmicpc.net/problem/1967
#include <iostream>
#include <vector>

#define MAX_NODE_SIZE 10'001

using namespace std;

struct Node {
	int node;
	int weight;
	Node(int n, int w): node(n), weight(w) {}
};

int diameter = 0;
vector<Node> adjList[MAX_NODE_SIZE];

void dfs( int me, int mom, int curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n - 1; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back( Node( b, c ) );
		adjList[b].push_back( Node( a, c ) );
	}

	for ( int i = 1; i <= n; i++)
		dfs( i, 0, 0 );

	cout << diameter << '\n';

	return 0;
}

void dfs( int me, int mom, int curr ) {
	if ( curr > diameter )
		diameter = curr;
	for ( Node& son : adjList[me] ) {
		if ( son.node != mom )
			dfs( son.node, me, curr + son.weight );
	}
}
