// Baekjoon01577_NumberOfStreet.cpp
// https://www.acmicpc.net/problem/1577
#include <iostream>
#include <vector>

using namespace std;

struct Position {
	int r, c;
	Position() {}
	Position( int row, int col ): r(row), c(col) {}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<Position> broken[101][101];
	for ( int i = 0; i < k; i++ ) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if ( a != c ) {
			if ( a < c )
				broken[a][b].push_back( Position( c, d ) );
			else
				broken[c][d].push_back( Position( a, b ) );
		} else {
			if ( b < d )
				broken[a][b].push_back( Position( c ,d ) );
			else
				broken[c][d].push_back( Position( a, b ) );
		}
	}

	long street[101][101] = { 1, };
	for ( int i = 1; i <= n; i++ ) {
		bool isBroken = false;
		vector<Position>& prevBroken = broken[i - 1][0];
		for ( int j = 0; j < prevBroken.size(); j++ ) {
			if ( prevBroken[j].r == i && prevBroken[j].c == 0 ) {
				isBroken = true;
				break;
			}
		}

		if ( isBroken )
			street[i][0] = 0;
		else
			street[i][0] = street[i - 1][0];
	}

	for ( int i = 1; i <= m; i++ ) {
		bool isBroken = false;
		vector<Position>& prevBroken = broken[0][i - 1];
		for ( int j = 0; j < prevBroken.size(); j++ ) {
			if ( prevBroken[j].r == 0 && prevBroken[j].c == i ) {
				isBroken = true;
				break;
			}
		}

		if ( isBroken )
			street[0][i] = 0;
		else
			street[0][i] = street[0][i - 1];
	}

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			bool isBroken = false;
			vector<Position>& prevBroken = broken[i - 1][j];
			for ( int k = 0; k < prevBroken.size(); k++ ) {
				if ( prevBroken[k].r == i && prevBroken[k].c == j ) {
					isBroken = true;
					break;
				}
			}

			if ( !isBroken ) street[i][j] += street[i - 1][j];

			isBroken = false;
			prevBroken = broken[i][j - 1];
			for ( int k = 0; k < prevBroken.size(); k++ ) {
				if ( prevBroken[k].r == i && prevBroken[k].c == j ) {
					isBroken = true;
					break;
				}
			}

			if ( !isBroken ) street[i][j] += street[i][j - 1];
		}
	}

	cout << street[n][m] << '\n';

	return 0;
}