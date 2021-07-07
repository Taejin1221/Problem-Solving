// Baekjoon03190_Snake.cpp
// https://www.acmicpc.net/problem/3190
#include <iostream>

using namespace std;

struct Position {
	int row, col;
	Position( ): row(0), col(0) { }
	Position( int r, int c ): row(r), col(c) { }

	Position operator+( Position target ) {
		return Position( row + target.row, col + target.col );
	}
};

const Position change[4] = { Position( -1, 0 ), Position( 0, 1 ), Position( 1, 0 ), Position( 0, -1 ) };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	// 0 => empty, positive => snake, -1 => apple
	int board[100][100] = { 1, };
	for ( int i = 0; i < k; i++ ) {
		int r, c;
		cin >> r >> c;
		r--, c--;

		board[r][c] = -1;
	}

	int l;
	cin >> l;

	pair<int, char> keyStroke[100];
	for ( int i = 0; i < l; i++ )
		cin >> keyStroke[i].first >> keyStroke[i].second;

	Position head = Position( 0, 0 ), tail = Position( 0, 0 );
	int direc = 1, num = 2;
	int keyIdx = 0, time = 1;
	while ( true ) {
		Position nextHead = head + change[direc], nextTail = tail;
		if ( ( 0 <= nextHead.row && nextHead.row < n ) && ( 0 <= nextHead.col && nextHead.col < n ) ) {
			int type = board[nextHead.row][nextHead.col];
			board[nextHead.row][nextHead.col] = num++;
			if ( type > 0 )
				break;
			else if ( type == 0 ) {
				for ( int i = 0; i < 4; i++ ) {
					Position next = tail + change[i];
					if ( ( 0 <= next.row && next.row < n ) && ( 0 <= next.col && next.col < n ) ) {
						if ( board[next.row][next.col] == board[tail.row][tail.col] + 1 ) {
							nextTail = next;
							break;
						}
					}
				}
				board[tail.row][tail.col] = 0;
			}

			head = nextHead;
			tail = nextTail;

			if ( keyIdx < l && keyStroke[keyIdx].first == time ) {
				if ( keyStroke[keyIdx].second == 'D' )
					direc = ( direc == 3 ? 0 : direc + 1 );
				else
					direc = ( direc == 0 ? 3 : direc - 1 );
				keyIdx++;
			}

			time++;
		} else {
			break;
		}
	}

	cout << time << '\n';

	return 0;
}