// Baekjoon01647_CityPartitionPlan.cpp
// https://www.acmicpc.net/problem/1647
#include <iostream>
#include <algorithm> /* sort() */

using namespace std;

struct Edge {
	int s, e, w;
	Edge( ) {}
	Edge( int start, int end, int weight ): s(start), e(end), w(weight) {}
};

int parents[100001];

bool compare( const Edge& e1, const Edge& e2 );
int Find( int target );
void Union( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	Edge edges[1000000];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		if ( a > b ) {
			edges[i].s = b;
			edges[i].e = a;
		} else {
			edges[i].s = a;
			edges[i].e = b;
		}
		edges[i].w = c;
	}
	sort( edges, edges + m, compare );

	for ( int i = 1; i <= n; i++ )
		parents[i] = i;

	int sum = 0;
	int num = 1, idx = 0;
	while ( num < n - 1 ) {
		Edge curr = edges[idx];

		if ( Find(curr.s) != Find(curr.e) ) {
			Union( curr.s, curr.e );
			sum += curr.w;
			num++;
		}

		idx++;
	}

	cout << sum << '\n';

	return 0;
}

bool compare( const Edge& e1, const Edge& e2 ) {
	if ( e1.w != e2.w )
		return e1.w < e2.w;
	else if ( e1.s != e2.s )
		return e1.s < e2.s;
	else
		return e1.e < e2.e;
}

int Find( int target ) {
	if ( parents[target] == target )
		return target;
	else
		return parents[target] = Find( parents[target] );
}

void Union( int a, int b ) {
	int aRoot = Find( a );
	int bRoot = Find( b );

	if ( aRoot < bRoot )
		parents[bRoot] = aRoot;
	else
		parents[aRoot] = bRoot;
}