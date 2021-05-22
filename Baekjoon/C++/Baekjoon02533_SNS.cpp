// Baekjoon02533_SNS.cpp
// https://www.acmicpc.net/problem/2533
#include <iostream>

#include <vector>

#define SIZE 1'000'001

using namespace std;

int dp[2][SIZE];
vector<int> adjList[SIZE];

int getMinEarlyadaptor( int node, int status, int mom ) {
	if ( dp[status][node] == -1 ) {
		int sum = 0;
		for ( int& son : adjList[node] ) {
			if ( son != mom ) {
				int value = getMinEarlyadaptor( son, !status, node );
				if ( status )
					value = min( value, getMinEarlyadaptor( son, status, node ) );

				sum += value;
			}
		}

		dp[status][node] = sum + status;
	}

	return dp[status][node];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n - 1; i++ ) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back( v );
		adjList[v].push_back( u );
	}

	fill( dp[0] + 1, dp[0] + n + 1, -1 );
	fill( dp[1] + 1, dp[1] + n + 1, -1 );

	for ( int i = 2; i <= n; i++ ) {
		if ( adjList[i].size() == 1 ) {
			dp[0][i] = 0;
			dp[1][i] = 1;
		}
	}

	int noEarly1 = getMinEarlyadaptor( 1, 0, 0 );
	int early1 = getMinEarlyadaptor( 1, 1, 0 );

	cout << min( noEarly1, early1 ) << '\n';

	return 0;
}