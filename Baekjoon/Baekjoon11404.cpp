// Baekjoon11404_Floyd.cpp
// https://www.acmicpc.net/problem/11404
#include <iostream>
#include <climits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	long long graph[101][101];
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ )
			graph[i][j] = INT_MAX;
		graph[i][i] = 0;
	}

	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a][b] = min( c, (int)graph[a][b] );
	}

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			for ( int k = 1; k <= n; k++ )
				graph[j][k] = min( graph[j][k], graph[j][i] + graph[i][k] );


	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( graph[i][j] == INT_MAX || graph[i][j] == 0 )
				cout << '0';
			else
				cout << graph[i][j];
			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}