// Baekjoon02468_SafeArea.cpp
// https://www.acmicpc.net/problem/2468
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n;
int area[100][100], visited[100][100];

void dfs( int row, int col ) {
	visited[row][col] = true;

	pii nexts[4] = {
		{ row - 1, col },
		{ row, col + 1 },
		{ row + 1, col },
		{ row, col - 1 }
	};

	for ( pii& next : nexts	) {
		int nextRow = next.first, nextCol = next.second;
		if ( (0 <= nextRow && nextRow < n) && (0 <= nextCol && nextCol < n ) ) {
			if ( !visited[nextRow][nextCol] )
				dfs(nextRow, nextCol);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> area[i][j];

	int ans = 1;
	for ( int fluid = 1; fluid <= 100; fluid++ ) {
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( area[i][j] <= fluid )
					visited[i][j] = true;
				else
					visited[i][j] = false;
			}
		}

		int curr = 0;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( !visited[i][j] ) {
					dfs( i, j );
					curr++;
				}
			}
		}

		ans = max( ans, curr );
	}

	cout << ans << '\n';

	return 0;
}
