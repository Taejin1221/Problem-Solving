// Baekjoon14621_LoveExceptMe.cpp
// https://www.acmicpc.net/problem/14621
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
	int v, u, w;
	Edge(): v(0), u(0), w(0) { }
	Edge( int v, int u, int w ): v(v), u(u), w(w) { }
	bool operator<( const Edge& comp ) const {
		return w < comp.w;
	}
};

int parent[1'000];
bool sexes[1'000];

int FindRoot( int a );
void Union( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < n; i++ ) {
		char sex;
		cin >> sex;

		if ( sex == 'W' )
			sexes[i] = true;
		parent[i] = i;
	}

	Edge edges[10'000];
	for ( int i = 0; i < m; i++ ) {
		int v, u, w;
		cin >> v >> u >> w;

		edges[i].v = v - 1;
		edges[i].u = u - 1;
		edges[i].w = w;
	}
	sort( edges, edges + m );

	int ans = 0;
	for ( int i = 0; i < m; i++ ) {
		Edge& curr = edges[i];

		if ( sexes[curr.u] != sexes[curr.v] ) {
			int vRoot = FindRoot( curr.v ), uRoot = FindRoot( curr.u );
			if ( vRoot != uRoot ) {
				Union( vRoot, uRoot );

				ans += curr.w;
			}
		}
	}

	int standard = FindRoot( 0 );
	bool isAllConnected = true;
	for ( int i = 1; i < n; i++ ) {
		if ( standard != FindRoot( i ) ) {
			isAllConnected = false;
			break;
		}
	}

	if ( isAllConnected )
		cout << ans << '\n';
	else
		cout << -1 << '\n';

	return 0;
}

int FindRoot( int a ) {
	return ( ( parent[a] == a ) ? a : FindRoot( parent[a] ) );
}

void Union( int a, int b ) {
	if ( a < b )
		parent[b] = a;
	else
		parent[a] = b;
}
