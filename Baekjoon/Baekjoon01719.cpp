// Baekjoon01719_Delivery.cpp
// https://www.acmicpc.net/problem/1719
#include <iostream>

#include <algorithm>

#define INF 1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int shortestCost[201][201];
	for ( int i = 1; i <= n; i++ )
		fill( shortestCost[i] + 1, shortestCost[i] + n + 1, INF );

	int shortestPath[201][201] = { 0, };
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		if ( shortestCost[a][b] > c ) {
			shortestCost[a][b] = c;
			shortestPath[a][b] = b;
		}

		if ( shortestCost[b][a] > c ) {
			shortestCost[b][a] = c;
			shortestPath[b][a] = a;
		}
	}

	for ( int k = 1; k <= n; k++ ) {
		for ( int i = 1; i <= n; i++ ) {
			for ( int j = 1; j <= n; j++ ) {
				if ( i != j ) {
					if ( shortestCost[i][j] > shortestCost[i][k] + shortestCost[k][j] ) {
						shortestCost[i][j] = shortestCost[i][k] + shortestCost[k][j];

						// path backtracking
						int target = k;
						while ( shortestPath[i][target] != target )
							target = shortestPath[i][target];
						shortestPath[i][j] = target;
					}
				}
			}
		}
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			if ( shortestPath[i][j] )
				cout << shortestPath[i][j] << ' ';
			else
				cout << '-' << ' ';
		}
		cout << '\n';
	}

	return 0;
}