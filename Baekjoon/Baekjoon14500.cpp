// Baekjoon14500_Tetromino.cpp
// https://www.acmicpc.net/problem/14500
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int rowChange[4] = { -1, 0, 1, 0 },
	colChange[4] = { 0, 1, 0, -1 };

int n, m, ans;
int paper[500][500];

bool isValid( pii curr, pii prev ) {
	if ( ( 0 <= curr.first && curr.first < n ) && ( 0 <= curr.second && curr.second < m ) )
		if ( !( curr.first == prev.first && curr.second == prev.second ) )
			return true;
	return false;
}

void PutFuckShape( pii curr, pii prev, int sum ) {
	for ( int i = 0; i < 3; i++ ) {
		pii next1 = { curr.first + rowChange[i], curr.second + colChange[i] };
		for ( int j = i + 1; j < 4; j++ ) {
			pii next2 = { curr.first + rowChange[j], curr.second + colChange[j] };
			if ( isValid( next1, prev ) && isValid( next2, prev ) ) {
				int tempSum = sum + paper[next1.first][next1.second] + paper[next2.first][next2.second];
				ans = max( ans, tempSum );
			}
		}
	}
}

void dfs( pii curr, pii prev, int sum, int num ) {
	if ( num == 4 ) {
		ans = max( ans, sum );
	} else {
		int nextNum = num + 1;
		for ( int i = 0; i < 4; i++ ) {
			pii next = { curr.first + rowChange[i], curr.second + colChange[i] };

			if ( isValid( next, prev ) ) {
				dfs( next, curr, sum + paper[next.first][next.second], nextNum );
				if ( nextNum == 2 )
					PutFuckShape( next, curr, sum + paper[next.first][next.second] );
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> paper[i][j];

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			dfs( { i, j }, { -1, -1 }, paper[i][j], 1 );

	cout << ans << '\n';

	return 0;
}
