// Baekjoon15681_TreeAndQuery.cpp
// https://www.acmicpc.net/problem/15681
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int dp[100'001], level[100'001];
vector<int> adjList[100'001];

void dfs( int root ) {
	for ( int& adj : adjList[root] ) {
		if ( level[adj] == -1 ) {
			level[adj] = level[root] + 1;
			dfs( adj );
		}
	}
}

int GetSubtreeNodeNum( int root ) {
	if ( dp[root] == -1 ) {
		int ans = 0;
		for ( int& adj : adjList[root] )
			if ( level[adj] > level[root] )
				ans += GetSubtreeNodeNum( adj );
		dp[root] = ans + 1;
	}

	return dp[root];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	for ( int i = 0; i < n - 1; i++ ) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back( v );
		adjList[v].push_back( u );
	}

	fill( level, level + n + 1, -1 );
	fill( dp, dp + n + 1, -1 );

	level[r] = 0;
	dfs( r );

	while ( q-- ) {
		int root;
		cin >> root;

		cout << GetSubtreeNodeNum( root ) << '\n';
	}

	return 0;
}