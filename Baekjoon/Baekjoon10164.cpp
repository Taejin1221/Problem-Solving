// Baekjoon10164_PathOnGrid.cpp
#include <iostream>

using namespace std;

int main(void) {
	int row, col, num;
	cin >> row >> col >> num;

	bool isFind = false;
	int targetRow = 0, targetCol = 0, curr = 1;
	for ( int i = 0; i < row; i++ ) {
		for ( int j = 0; j < col; j++ ) {
			if ( curr == num ) {
				targetRow = i, targetCol = j;
				isFind = true;
				break;
			}
			curr++;
		}

		if ( isFind )
			break;
	}

	int dp[15][15] = { 0, };
	for ( int i = 0; i < row; i++ )
		dp[i][0] = 1;
	for ( int j = 0; j < col; j++ )
		dp[0][j] = 1;

	for ( int i = 1; i <= targetRow; i++ ) {
		for ( int j = 1; j <= targetCol; j++ ) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int targetPath = dp[targetRow][targetCol];
	for ( int i = targetRow; i < row; i++ )
		dp[i][targetCol] = 1;
	for ( int j = targetCol; j < col; j++ )
		dp[targetRow][j] = 1;

	for ( int i = targetRow + 1; i < row; i++ )
		for ( int j = targetCol + 1; j < col; j++ )
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

	cout << dp[row - 1][col - 1] * targetPath << '\n';

	return 0;
}