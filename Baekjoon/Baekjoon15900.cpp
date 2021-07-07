// Baekjoon15900_EscapeTree.cpp
// https://www.acmicpc.net/problem/15900
// UCPC 2018 Preliminary D
#include <iostream>
#include <vector>

#define endl '\n'
#define MAX_NODE_SIZE 500'001

using namespace std;

int edges;
vector<int> tree[MAX_NODE_SIZE];

void dfs( int n, int me, int mom );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	tree[1].push_back( 0 );
	for ( int i = 0; i < n - 1; i++ ) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back( b );
		tree[b].push_back( a );
	}

	dfs( 0, 1, 0 );

	if ( edges % 2 )
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

void dfs( int n, int me, int mom ) {
	if ( tree[me].size() == 1 )
		edges += n;
	else
		for ( int son : tree[me] )
			if ( son != mom )
				dfs( n + 1, son, me );
}