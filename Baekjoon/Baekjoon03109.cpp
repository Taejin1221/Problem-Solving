// Baekjoon03109_PLINOVOD.cpp
#include <iostream>

using namespace std;

int maxRow, maxCol;
bool visited[10'000][500];
char map[10'000][501];

bool dfs( int row, int col ) {
	if ( col == maxCol - 1 )
		return true;
	else {
		pair<int, int> nexts[3] = {
			{ row - 1, col + 1 },
			{ row, col + 1 },
			{ row + 1, col + 1 }
		};

		for ( pair<int, int>& next : nexts ) {
			if ( ( 0 <= next.first && next.first < maxRow ) ) {
				if ( !visited[next.first][next.second] && map[next.first][next.second] != 'x' ) {
					visited[next.first][next.second] = true;
					if ( dfs( next.first, next.second ) )
						return true;
				}
			}
		}

		return false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> maxRow >> maxCol;

	for ( int i = 0; i < maxRow; i++ )
		cin >> map[i];

	int ans = 0;
	for ( int i = 0; i < maxRow; i++ ) {
		visited[i][0] = true;
		if ( dfs( i, 0 ) )
			ans++;
	}

	cout << ans << '\n';

	return 0;
}