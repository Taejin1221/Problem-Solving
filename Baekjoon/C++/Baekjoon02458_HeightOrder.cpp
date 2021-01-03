// Baekjoon02458_HeightOrder.cpp
// https://www.acmicpc.net/problem/2458
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool adjMatrix[501][501] = { false, };
	for ( int i = 0; i < m; i++ ) {
		int v, u;
		cin >> v >> u;

		adjMatrix[v][u] = true;
	}

	for ( int k = 1; k <= n; k++ )
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= n; j++ )
				if ( i != j )
					if ( adjMatrix[i][k] && adjMatrix[k][j] )
						adjMatrix[i][j] = true;

	int count = 0;
	for ( int i = 1; i <= n; i++ ) {
		int currCount = 0;
		for ( int j = 1; j <= n; j++ )
			if ( adjMatrix[i][j] )
				currCount++;

		for ( int j = 1; j <= n; j++ )
			if ( adjMatrix[j][i] )
				currCount++;

		if ( currCount == n - 1 )
			count++;
	}

	cout << count << '\n';

	return 0;
}
