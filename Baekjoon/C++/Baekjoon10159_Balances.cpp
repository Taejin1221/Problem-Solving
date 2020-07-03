// Baekjoon10159_Balances.cpp
// https://www.acmicpc.net/problem/10159
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool adjMatrix[101][101] = { false, };
	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		adjMatrix[a][b] = true;
	}

	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			for ( int k = 1; k <= n; k++ )
				if (adjMatrix[j][i] && adjMatrix[i][k])
					adjMatrix[j][k] = 1;

	for ( int i = 1; i <= n; i++ ) {
		int count = 1;
		for ( int j = 1; j <= n; j++ )
			if ( adjMatrix[i][j] || adjMatrix[j][i] )
				count++;
		cout << n - count << '\n';
	}

	return 0;
}