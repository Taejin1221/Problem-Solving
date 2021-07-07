// Baekjoon06497_PowerShortages.cpp
// https://www.acmicpc.net/problem/6497
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int v, u, w;
	Edge( ): v(0), u(0), w(0) { }
	Edge( int v, int u, int w ): v(v), u(u), w(w) { }
	bool operator<( const Edge& edge2) const {
		return w < edge2.w;
	}
};

int parent[200'000];

int FindRoot( int target ) {
	return ( parent[target] == target ? target : FindRoot( parent[target] ) );
}

void Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	if ( aRoot < bRoot )
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	while ( !(m == 0 && n == 0) ) {
		int sum = 0;
		Edge edges[200'000];
		for ( int i = 0; i < n; i++) {
			cin >> edges[i].v >> edges[i].u >> edges[i].w;
			sum += edges[i].w;
		}

		sort( edges, edges + n );

		for ( int i = 0; i < m; i++ )
			parent[i] = i;

		int minimum = 0;
		for ( int i = 0; i < n; i++ ) {
			Edge& curr = edges[i];

			int vRoot = FindRoot( curr.v ), uRoot = FindRoot( curr.u );
			if ( vRoot != uRoot ) {
				Union( vRoot, uRoot );
				minimum += curr.w;
			}
		}
		
		cout << sum - minimum << '\n';

		cin >> m >> n;
	}

	return 0;
}
