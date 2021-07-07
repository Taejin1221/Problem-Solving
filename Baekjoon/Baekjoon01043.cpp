// Baekjoon01043_Lie.cpp
// https://www.acmicpc.net/problem/1043
#include <iostream>
#include <vector>

using namespace std;

int parent[51], truth[51];

int FindRoot( int target ) {
	return ( target == parent[target] ? target : FindRoot( parent[target] ) );
}

void Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	if ( truth[aRoot] )
		parent[bRoot] = aRoot;
	else if ( truth[bRoot] )
		parent[aRoot] = bRoot;
	else {
		parent[aRoot] = bRoot;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int t;
	cin >> t;
	while ( t-- ) {
		int temp;
		cin >> temp;
		truth[temp] = true;
	}

	for ( int i = 1; i <= n; i++ )
		parent[i] = i;

	vector<int> parties[50];
	for ( int i = 0; i < m; i++ ) {
		int t;
		cin >> t;

		int prev;
		cin >> prev;
		t--;

		parties[i].push_back( prev );

		while ( t-- ) {
			int temp;
			cin >> temp;
			parties[i].push_back( temp );

			Union( temp, prev );
			prev = temp;
		}
	}

	int count = 0;
	for ( int i = 0; i < m; i++ ) {
		bool canLie = true;
		for ( int& people : parties[i] ) {
			if ( truth[FindRoot(people)] ) {
				canLie = false;
				break;
			}
		}

		if ( canLie )
			count++;
	}
	
	cout << count << '\n';

	return 0;
}
