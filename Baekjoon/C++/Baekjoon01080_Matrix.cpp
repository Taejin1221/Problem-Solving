// Baekjoon01080_Matrix.cpp
// https://www.acmicpc.net/problem/1080
#include <iostream>

using namespace std;

void Flip( bool mat[][50], int maxRow, int maxCol, int currRow, int currCol );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	char A[50][51], B[50][51];
	for ( int i = 0; i < n; i++ )
		cin >> A[i];

	int trueNum = 0;
	bool matrix[50][50];
	for ( int i = 0; i < n; i++ ) {
		cin >> B[i];
		for ( int j = 0; j < m; j++ ) {
			matrix[i][j] = ( A[i][j] == B[i][j] );
			if ( matrix[i][j] )
				trueNum++;
		}
	}

	int ans = 0;
	bool canChage = true;
	if ( n < 3 || m < 3 ) {
		canChage = (trueNum == n * m);
	} else {
		while ( trueNum != n * m ) {
			if ( ans >= 10'000 ) {
				canChage = false;
				break;
			}

			bool isBreak = false;
			for ( int i = 0; i < n; i++ ) {
				for ( int j = 0; j < m; j++ ) {
					if ( !matrix[i][j] ) {
						Flip( matrix, n, m, i, j );
						ans++;

						isBreak = true;
						break;
					}
				}

				if ( isBreak )
					break;
			}

			trueNum = 0;
			for ( int i = 0; i < n; i++ )
				for ( int j = 0; j < m; j++ )
					if ( matrix[i][j] )
						trueNum++;
		}
	}

	if ( canChage )
		cout << ans;
	else
		cout << -1;
	cout << '\n';

	return 0;
}

void Flip( bool mat[][50], int maxRow, int maxCol, int currRow, int currCol ) {
	int startRow, startCol;
	if ( currRow == maxRow - 1 )
		startRow = currRow - 2;
	else if ( currRow == maxRow - 2 )
		startRow = currRow - 1;
	else
		startRow = currRow;

	if ( currCol == maxCol - 1 )
		startCol = currCol - 2;
	else if ( currCol == maxCol - 2 )
		startCol = currCol - 1;
	else
		startCol = currCol;


	for ( int i = 0; i < 3; i++ )
		for ( int j = 0; j < 3; j++ )
			mat[startRow + i][startCol + j] = !mat[startRow + i][startCol + j];
}
