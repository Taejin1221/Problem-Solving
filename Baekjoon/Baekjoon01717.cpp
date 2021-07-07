// Baekjoon01717_RepresentSet.cpp
// https://www.acmicpc.net/problem/1717
#include <iostream>

using namespace std;

int parent[1000001];

int FindRoot( int target );
void Union( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ )
		parent[i] = i;

	while ( m-- ) {
		int a, b, c;
		cin >> a >> b >> c;

		if ( !a )
			Union( b, c );
		else {
			if ( FindRoot( b ) == FindRoot( c ) )
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}

int FindRoot( int target ) {
	if ( target == parent[target] )
		return target;
	else
		return ( parent[target] = FindRoot( parent[target] ) );
}

void Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	if ( aRoot < bRoot )
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}
