// Baekjoon01976_GoTrip.cpp
// https://www.acmicpc.net/problem/1976
#include <iostream>

using namespace std;

int parents[200];

int Find( int target );
void Union( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for ( int i = 0; i < n; i++ ) parents[i] = i;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			int temp;
			cin >> temp;

			if ( temp )
				Union( i, j );
		}
	}
	
	bool connected = true;
	int route[1000];
	cin >> route[0];
	for ( int i = 1; i < m; i++ ) {
		cin >> route[i];
		if ( Find( route[i - 1] - 1 ) != Find( route[i] -1 ) ) {
			connected = false;
			break;
		}
	}

	if (connected)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}

int Find( int target ) {
	return ( parents[target] = ( (parents[target] == target ) ? target : ( Find( parents[target] ) ) ) );
}

void Union( int a, int b ) {
	int aRoot = Find( a );
	int bRoot = Find( b );

	if ( aRoot < bRoot )
		parents[bRoot] = aRoot;
	else
		parents[aRoot] = bRoot;
}