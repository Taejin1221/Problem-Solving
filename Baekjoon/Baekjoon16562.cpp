// Baekjoon16562_FriendCost.cpp
// https://www.acmicpc.net/problem/16562
#include <iostream>

#define MAX_SIZE 10'001

using namespace std;

int parents[MAX_SIZE];
int costs[MAX_SIZE];

int FindRoot( int target ) {
	return ( target == parents[target] ? target : FindRoot( parents[target] ) );
}

void Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	if ( costs[aRoot] < costs[bRoot] )
		parents[bRoot] = aRoot;
	else
		parents[aRoot] = bRoot;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for ( int i = 1; i <= n; i++ ) {
		parents[i] = i;
		cin >> costs[i];
	}

	for ( int i = 0; i < m; i++ ) {
		int v, w;
		cin >> v >> w;

		Union( v, w );
	}

	int sumCost = 0;
	bool isCheck[MAX_SIZE] = { false, };
	for ( int i = 1; i <= n; i++ ) {
		int currRoot = FindRoot( i );
		if ( !isCheck[currRoot] ) {
			sumCost += costs[currRoot];
			isCheck[currRoot] = true;
		}
	}

	if ( sumCost > k )
		cout << "Oh no";
	else
		cout << sumCost;
	cout << '\n';

	return 0;
}
