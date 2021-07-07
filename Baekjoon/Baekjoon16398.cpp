// Baekjoon16398_ConnectPlanet.cpp
// https://www.acmicpc.net/problem/16398
#include <iostream>

#include <algorithm>

#define MAX_NODE 1'001
#define MAX_EDGE 500'000

using namespace std;

struct Edge {
	int v, u, weight;
	Edge( ): v( 0 ), u( 0 ), weight( 0 ) { }
	Edge( int v, int u, int w ): v(v), u(u), weight(w) { }
	bool operator<( const Edge& e2 ) const {
		return weight < e2.weight;
	}
};

int parent[MAX_NODE];

int GetRoot( int curr ) {
	if ( parent[curr] == curr )
		return curr;
	else
		return parent[curr] = GetRoot( parent[curr] );
}

void Union( int aRoot, int bRoot ) {
	if ( aRoot < bRoot )
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Edge edges[MAX_EDGE];

	int temp, edgeIdx = 0;
	for ( int i = 1; i <= n; i++ ) {
		parent[i] = i;
		for ( int j = 1; j <= i; j++ )
			cin >> temp;

		for ( int j = i + 1; j <= n; j++ ) {
			cin >> temp;
			edges[edgeIdx++] = Edge( i, j, temp );
		}
	}

	sort( edges, edges + edgeIdx );

	int connected = 0;

	long long ans = 0ll;
	for ( int i = 0; i < edgeIdx && connected < n - 1; i++ ) {
		int v = edges[i].v, u = edges[i].u;
		int vRoot = GetRoot( v ), uRoot = GetRoot( u );
		if ( vRoot != uRoot ) {
			Union( vRoot, uRoot );

			connected++;

			ans = ans + edges[i].weight;
		}
	}

	cout << ans << '\n';

	return 0;
}