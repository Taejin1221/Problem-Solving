// Baekjoon01520_Downhill.cpp
// https://www.acmicpc.net/problem/1520
#include <iostream>

using namespace std;

int n, m;
int map[500][500];
int dp[500][500];

int AllPath( int row, int col ) {
	if ( dp[row][col] != -1 ) {
		int up = 0, left = 0, bottom = 0, right = 0;

		if ( row > 0 && map[row - 1][col] > map[row][col] )
			up = AllPath( row - 1, col );
		if ( col > 0 && map[row][col - 1] > map[row][col] )
			left = AllPath( row, col - 1 );
		if ( row < n - 1 && map[row + 1][col] > map[row][col] )
			bottom = AllPath( row + 1, col );
		if ( col < m - 1 && map[row][col + 1] > map[row][col] )
			right = AllPath( row, col + 1 );
		dp[row][col] = up + left + bottom + right;
	}
	return dp[row][col];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ ) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	dp[0][0] = 1;
	cout << AllPath( n - 1, m - 1) << '\n';

	return 0;
}