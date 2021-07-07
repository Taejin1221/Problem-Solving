// Baekjoon11660_PrefixSum5.cpp
// https://www.acmicpc.net/problem/11660
#include <iostream>

using namespace std;

#define MAX_MAT_SIZE 1024
#define MAX_PRE_SIZE 1025

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mat[MAX_MAT_SIZE][MAX_MAT_SIZE];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> mat[i][j];

	int prefix[MAX_PRE_SIZE][MAX_PRE_SIZE] = { 0, };
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= n; j++ )
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + mat[i - 1][j - 1];

	while ( m-- ) {
		int row1, col1, row2, col2;
		cin >> row1 >> col1 >> row2 >> col2;

		int ans = prefix[row2][col2] \
		- prefix[row2][col1 - 1] \
		- prefix[row1 - 1][col2] \
		+ prefix[row1 - 1][col1 - 1];

		cout << ans << '\n';
	}

	return 0;
}