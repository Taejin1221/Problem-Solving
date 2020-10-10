// Baekjoon02167_SumOfMatrix.cpp
// https://www.acmicpc.net/problem/2167
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mat[300][300];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> mat[i][j];

	int k;
	cin >> k;
	while ( k-- ) {
		int start_i, start_j, x, y;
		cin >> start_i >> start_j >> x >> y;

		int sum = 0;
		for ( int i = start_i - 1; i < x; i++ )
			for ( int j = start_j - 1; j < y; j++ )
				sum += mat[i][j];

		cout << sum << '\n';
	}

	return 0;
}