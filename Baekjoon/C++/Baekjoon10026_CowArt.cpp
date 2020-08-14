// Baekjoon10026_CowArt.cpp
// https://www.acmicpc.net/problem/10026
#include <iostream>
#include <queue>

using namespace std;

int n;
char pic[101][101];
bool visited[2][100][100];

void bfs( pair<int, int> curr );
void bfs2( pair<int, int> curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> pic[i];

	void (*bfs_func[2])(pair<int, int>) = { bfs, bfs2 };
	for ( int t = 0; t < 2; t++ ) {
		int section = 0;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( !visited[t][i][j] ) {
					visited[t][i][j] = true;
					bfs_func[t]( { i, j } );
					section++;
				}
			}
		}
		cout << section << ' ';
	}
	cout << '\n';

	return 0;
}

void bfs( pair<int, int> curr ) {
	char color = pic[curr.first][curr.second];

	queue<pair<int, int>> q;
	q.push( curr );
	while ( !q.empty() ) {
		pair<int, int> currPos = q.front(); q.pop();

		pair<int, int> surr[4] = {
			{ currPos.first - 1, currPos.second },
			{ currPos.first, currPos.second + 1 },
			{ currPos.first + 1, currPos.second },
			{ currPos.first, currPos.second - 1 }
		};

		for ( pair<int, int>& next : surr ) {
			int nextRow = next.first, nextCol = next.second;
			if ( ( 0 <= nextRow && nextRow < n ) && ( 0 <= nextCol && nextCol < n ) ) {
				if ( (!visited[0][nextRow][nextCol]) && (pic[nextRow][nextCol] == color) ) {
					visited[0][nextRow][nextCol] = true;
					q.push( { nextRow, nextCol } );
				}
			}
		}
	}
}

void bfs2( pair<int, int> curr ) {
	char color = pic[curr.first][curr.second];

	queue<pair<int, int>> q;
	q.push( curr );
	while ( !q.empty() ) {
		pair<int, int> currPos = q.front(); q.pop();

		pair<int, int> surr[4] = {
			{ currPos.first - 1, currPos.second },
			{ currPos.first, currPos.second + 1 },
			{ currPos.first + 1, currPos.second },
			{ currPos.first, currPos.second - 1 }
		};

		for ( pair<int, int>& next : surr ) {
			int nextRow = next.first, nextCol = next.second;
			if ( ( 0 <= nextRow && nextRow < n ) && ( 0 <= nextCol && nextCol < n ) ) {
				if ( (!visited[1][nextRow][nextCol]) ) {
					if ( ((color == 'R' || color == 'G') && (pic[nextRow][nextCol] == 'R' || pic[nextRow][nextCol] == 'G')) ||
					(color == 'B' && pic[nextRow][nextCol] == 'B') ) {
						visited[1][nextRow][nextCol] = true;
						q.push( { nextRow, nextCol } );
					}
				}
			}
		}
	}
}