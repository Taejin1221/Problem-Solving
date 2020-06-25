// Baekjoon01890_Jump.cpp
// https://www.acmicpc.net/problem/1890
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int board[100][100];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> board[i][j];

	long long path[100][100] = { 1, };
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			if ( path[i][j] && board[i][j] ) {
				int me = board[i][j];
				if ( i + me < n )
					path[i + me][j] += path[i][j];
				if ( j + me < n )
					path[i][j + me] += path[i][j];
			}
		}
	}

	cout << path[n - 1][n - 1] << '\n';

	return 0;
}