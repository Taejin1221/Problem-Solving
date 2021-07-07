// Baekjoon12100_2048(Easy).cpp
// https://www.acmicpc.net/problem/12100

/* Review
 * Date
 01/11/2021

 * Comment
 별 특별할 것 없는 단순 구현이다. 반복횟수가 5밖에 안되기 때문에 5번 다 4방향으로 움직여보고 가장 큰 값을 찾으면 된다.
 중간에 0이 없도록 한 방향으로 모든 숫자들을 옮기고, 한 방향으로 같은 숫자가 2개 연속되면 더한다. 이후 중간에 0이 없도록 한 방향으로 모든 숫자들을 옮겼다.
 다른 사람의 Solution을 보니 Up만 구현하고 90도로 board를 돌려서 4번 구하더라. 그 방식이 굉장히 효율적일 것 같다.

 * Solution
 Move
 1. 숫자들 사이에 0이 없도록 모든 숫자를 이동하려는 방향으로 옮긴다.
 2. 숫자들을 이동하려는 방향의 반대방향으로 탐색하며 똑같은 숫자가 두개 연속이라면 더하고, 뒤의 숫자에 0을 채운다.
 3. 다시 1번을 반복한다.

 위의 Move를 4방향으로 모두 실행해보고, 5번 움직였을 시 가장 큰 숫자를 센다.
*/

#include <iostream>
#include <vector>

using namespace std;

int n, ans;

void MoveAll( vector<vector<int>> board, int time );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<vector<int>> board ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> board[i][j];

	MoveAll( board, 0 );

	cout << ans << '\n';

	return 0;
}

vector<vector<int>> MoveUp( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( board[j][i] != 0 )
				newBoard[zeroIdx++][i] = board[j][i];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n - 1; j++ ) {
			if ( newBoard[j][i] != 0 && newBoard[j][i] == newBoard[j + 1][i] ) {
				newBoard[j][i] *= 2;
				newBoard[j + 1][i] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( newBoard[j][i] != 0 ) {
				int temp = newBoard[j][i];
				newBoard[j][i] = 0;
				newBoard[zeroIdx++][i] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveDown( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) { // column
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) { // row
			if ( board[j][i] != 0 )
				newBoard[zeroIdx--][i] = board[j][i];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j > 0; j-- ) {
			if ( newBoard[j][i] != 0 && newBoard[j][i] == newBoard[j - 1][i] ) {
				newBoard[j][i] *= 2;
				newBoard[j - 1][i] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( newBoard[j][i] != 0 ) {
				int temp = newBoard[j][i];
				newBoard[j][i] = 0;
				newBoard[zeroIdx--][i] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveLeft( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( board[i][j] != 0 )
				newBoard[i][zeroIdx++] = board[i][j];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n - 1; j++ ) {
			if ( newBoard[i][j] != 0 && newBoard[i][j] == newBoard[i][j + 1] ) {
				newBoard[i][j] *= 2;
				newBoard[i][j + 1] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = 0;
		for ( int j = 0; j < n; j++ ) {
			if ( newBoard[i][j] != 0 ) {
				int temp = newBoard[i][j];
				newBoard[i][j] = 0;
				newBoard[i][zeroIdx++] = temp;
			}
		}
	}

	return newBoard;
}

vector<vector<int>> MoveRight( vector<vector<int>>& board ) {
	vector<vector<int>> newBoard ( n, vector<int> ( n ) );
	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( board[i][j] != 0 )
				newBoard[i][zeroIdx--] = board[i][j];
		}
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = n - 1; j > 0; j-- ) {
			if ( newBoard[i][j] != 0 && newBoard[i][j] == newBoard[i][j - 1] ) {
				newBoard[i][j] *= 2;
				newBoard[i][j - 1] = 0;
			}
		}
	}

	for ( int i = 0; i < n; i++ ) {
		int zeroIdx = n - 1;
		for ( int j = n - 1; j >= 0; j-- ) {
			if ( newBoard[i][j] != 0 ) {
				int temp = newBoard[i][j];
				newBoard[i][j] = 0;
				newBoard[i][zeroIdx--] = temp;
			}
		}
	}

	return newBoard;
}


void MoveAll( vector<vector<int>> board, int time ) {
	if ( time == 5 ) {
		int maxScore = 0;
		for ( vector<int>& row : board )
			for ( int& value : row )
				maxScore = max( maxScore, value );

		ans = max( ans, maxScore );
	} else {
		int nextTime = time + 1;
		MoveAll( MoveUp( board ), nextTime );
		MoveAll( MoveDown( board ), nextTime );
		MoveAll( MoveLeft( board ), nextTime );
		MoveAll( MoveRight( board ), nextTime );
	}
}
