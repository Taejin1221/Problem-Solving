// Baekjoon11780_Floyd2.cpp
// https://www.acmicpc.net/problem/11780
#include <iostream>

#include <vector>
#include <algorithm>

#define INF 2'000'000'000l

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	long shortestPath[101][101];
	for ( int i = 1; i <= n; i++ )
		fill( shortestPath[i] + 1, shortestPath[i] + n + 1, INF );

	int path[101][101] = { 0, };
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		if ( shortestPath[a][b] > c ) {
			shortestPath[a][b] = c;
			path[a][b] = a;
		}
	}

	for ( int k = 1; k <= n; k++ ) {
		for ( int i = 1; i <= n; i++ ) {
			for ( int j = 1; j <= n; j++ ) {
				if ( i != j ) {
					if ( shortestPath[i][j] > shortestPath[i][k] + shortestPath[k][j] ) {
						shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];

						int start = i, end = k;
						while ( path[start][end] != i )
							end = path[start][end];
						path[i][j] = end;
					}
				}
			}
		}
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( shortestPath[i][j] != INF )
				cout << shortestPath[i][j] << ' ';
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( shortestPath[i][j] == INF ) {
				cout << 0;
			} else {
				vector<int> path_i_to_j;
				path_i_to_j.push_back( i );

				int start = i, end = j;
				while ( path[start][end] != start ) {
					path_i_to_j.push_back( path[start][end] );
					start = path[start][end];
				}
				path_i_to_j.push_back( j );

				int size = path_i_to_j.size();

				cout << size << ' ';
				for ( int idx = 0; idx < size; idx++ )
					cout << path_i_to_j[idx] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}