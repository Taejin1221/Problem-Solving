// Baekjoon01774_BuildingRoads.cpp
// https://www.acmicpc.net/problem/1774
#include <iostream>

#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
	int u, v;
	double cost;
	Edge( ): u( 0 ), v( 0 ), cost( 0.0 ) { }
	bool operator<( const Edge& e2 ) const {
		return cost < e2.cost;
	}
};

int parent[1'001];

int FindRoot( int target ) {
	return ( parent[target] == target ) ? target : FindRoot( parent[target] );
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

	int n, m;
	cin >> n >> m;

	pair<int, int> gods[1'001];
	for ( int i = 1; i <= n; i++ )
		cin >> gods[i].first >> gods[i].second;

	int edgeIdx = 0;
	Edge edges[1'000'000];
	for ( int i = 1; i <= n; i++ ) {
		parent[i] = i;
		for ( int j = i + 1; j <= n; j++ ) {
				edges[edgeIdx].u = i;
				edges[edgeIdx].v = j;
				edges[edgeIdx++].cost = sqrt( pow( gods[i].first - gods[j].first, 2 ) + pow( gods[i].second - gods[j].second, 2 ) );
		}
	}

	sort( edges, edges + edgeIdx );

	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;
		Union( FindRoot( a ), FindRoot( b ) );
	}

	double tunnel = 0.0;
	for ( int i = 0; i < edgeIdx; i++ ) {
		int u = edges[i].u, v = edges[i].v;

		int uRoot = FindRoot( u ), vRoot = FindRoot( v );
		if ( uRoot != vRoot ) {
			Union( uRoot, vRoot );

			tunnel += edges[i].cost;
		}
	}

	cout << fixed;
	cout.precision( 2 );
	cout << tunnel << '\n';

	return 0;
}