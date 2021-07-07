// Baekjoon01100_WhiteCell.cpp
// https://www.acmicpc.net/problem/1100
#include <iostream>

using namespace std;

int main(void) {
	char board[8][8];
	for ( int i = 0; i < 8; i++ )
		cin >> board[i];

	int ans = 0;
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			if ( !(( i + j ) % 2) && board[i][j] == 'F' )
				ans++;

	cout << ans << endl;

	return 0;
}