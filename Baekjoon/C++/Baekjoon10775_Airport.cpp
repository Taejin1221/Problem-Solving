// Baekjoon10775_Airport.cpp
// https://www.acmicpc.net/problem/10775
#include <iostream>

using namespace std;

int parents[100001];
	
int FindRoot( int a ) {
	if ( parents[a] == a )
		return a;
	else
		return parents[a] = FindRoot( parents[a] );
}

void Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	parents[aRoot] = bRoot;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int gates, planes;
	cin >> gates >> planes;

	for ( int i = 1; i <= gates; i++ )
		parents[i] = i;

	int maxPlanes = 0;
	while ( planes-- ) {
		int plane;
		cin >> plane;

		int temp = FindRoot( plane );
		if ( temp ) {
			Union( temp, temp - 1 );
			maxPlanes++;
		}
		else
			break;
	}

	cout << maxPlanes << '\n';

	return 0;
}