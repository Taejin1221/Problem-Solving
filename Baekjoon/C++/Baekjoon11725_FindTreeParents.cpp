// Baekjoon11725_FindTreeParents.cpp
// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>

#define MAX_SIZE 100'001

using namespace std;

int parents[MAX_SIZE];
vector<int> adjList[MAX_SIZE];

void dfs( int me, int mom );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 1; i < n; i++ ) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back( b );
		adjList[b].push_back( a );
	}

	dfs( 1, 0 );

	for ( int i = 2; i <= n; i++ )
		cout << parents[i] << '\n';

	return 0;
}

void dfs( int me, int mom ) {
	parents[me] = mom;

	for ( int& son : adjList[me] ) {
		if ( son != mom )
			dfs( son, me );
	}
}