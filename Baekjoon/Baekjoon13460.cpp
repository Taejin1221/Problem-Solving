// Baekjoon13460_MarbleEscape.cpp
// https://www.acmicpc.net/problem/13460
#include <iostream>

#include <queue>

using namespace std;

struct Position {
	int row, col;
	Position( int r, int c ): row( r ), col ( c ) { }
	bool operator==( Position& target ) {
		return ( row == target.row && col == target.col );
	}
};

struct Node {
	Position red, blue;
	int time;
	Node(): red( 0, 0 ), blue( 0, 0 ), time( 0 ) { }
	Node( Position r, Position b, int t ): red( r ), blue( b ), time( t ) { }
};

int maxRow, maxCol;
char board[10][11];

Node TiltUp( Node curr, int& isEnd );
Node TiltRight( Node curr, int& isEnd );
Node TiltDown( Node curr, int& isEnd );
Node TiltLeft( Node curr, int& isEnd );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Node start;
	cin >> maxRow >> maxCol;
	for ( int i = 0; i < maxRow; i++ ) {
		cin >> board[i];

		for ( int j = 0; j < maxCol; j++ ) {
			if ( board[i][j] == 'R' ) {
				start.red = Position( i, j );
				board[i][j] = '.';
			}
			else if ( board[i][j] == 'B' ) {
				start.blue = Position( i, j );
				board[i][j] = '.';
			}
		}
	}

	Node (*Tilts[4])( Node, int& ) = { TiltUp, TiltRight, TiltDown, TiltLeft };

	int ans = -1;
	queue<Node> q;
	bool visited[10][10][10][10] = { false, };

	q.push( start );
	visited[start.red.row][start.red.col][start.blue.row][start.blue.col] = true;
	while ( !q.empty() ) {
		Node curr = q.front(); q.pop();

		bool isEnd = false;
		for ( int i = 0; i < 4; i++ ) {
			int marbleStatus;
			Node next = Tilts[i]( curr, marbleStatus );

			if ( next.time > 10 )
				continue;

			if ( marbleStatus == 0 ) {
				if ( !visited[next.red.row][next.red.col][next.blue.row][next.blue.col] ) {
					visited[next.red.row][next.red.col][next.blue.row][next.blue.col] = true;
					q.push( next );
				}
			} else if ( marbleStatus == 1 ) {
				ans = next.time;
				isEnd = true;
				break;
			}
		}

		if ( isEnd )
			break;
	}

	cout << ans << '\n';

	return 0;
}

Position RollUp( Position target, bool& isEscape ) {
	int currRow;
	for ( currRow = target.row; board[currRow][target.col] != '#'; currRow-- ) {
		if ( board[currRow][target.col] == 'O' ) {
			isEscape = true;
			break;
		}
	}

	return Position( currRow + 1, target.col );
}

Node TiltUp( Node curr, int& isEnd ) {
	bool redEscape = false;
	Position nextRed = RollUp( curr.red, redEscape );

	bool blueEscape = false;
	Position nextBlue = RollUp( curr.blue, blueEscape );

	if ( blueEscape )
		isEnd = -1;
	else {
		if ( redEscape )
			isEnd = 1;
		else
			isEnd = 0;
	}

	if ( nextRed == nextBlue ) {
		// red is on upper side than blue
		if ( curr.red.row < curr.blue.row )
			nextBlue.row++;
		else
			nextRed.row++;
	}

	return Node( nextRed, nextBlue, curr.time + 1 );
}

Position RollRight( Position target, bool& isEscape ) {
	int currCol = target.col;
	for ( currCol = target.col; board[target.row][currCol] != '#'; currCol++ ) {
		if ( board[target.row][currCol] == 'O' ) {
			isEscape = true;
			break;
		}
	}

	return Position( target.row, currCol - 1 );
}

Node TiltRight( Node curr, int& isEnd ) {
	bool redEscape = false;
	Position nextRed = RollRight( curr.red, redEscape );

	bool blueEscape = false;
	Position nextBlue = RollRight( curr.blue, blueEscape );

	if ( blueEscape )
		isEnd = -1;
	else {
		if ( redEscape )
			isEnd = 1;
		else
			isEnd = 0;
	}

	if ( nextRed == nextBlue ) {
		// red is on right side than blue
		if ( curr.red.col > curr.blue.col )
			nextBlue.col--;
		else
			nextRed.col--;
	}

	return Node( nextRed, nextBlue, curr.time + 1 );
}

Position RollDown( Position target, bool& isEscape ) {
	int currRow;
	for ( currRow = target.row; board[currRow][target.col] != '#'; currRow++ ) {
		if ( board[currRow][target.col] == 'O' ) {
			isEscape = true;
			break;
		}
	}

	return Position( currRow - 1, target.col );
}

Node TiltDown( Node curr, int& isEnd ) {
	bool redEscape = false;
	Position nextRed = RollDown( curr.red, redEscape );

	bool blueEscape = false;
	Position nextBlue = RollDown( curr.blue, blueEscape );

	if ( blueEscape )
		isEnd = -1;
	else {
		if ( redEscape )
			isEnd = 1;
		else
			isEnd = 0;
	}

	if ( nextRed == nextBlue ) {
		// red is on bottom side than blue
		if ( curr.red.row > curr.blue.row )
			nextBlue.row--;
		else
			nextRed.row--;
	}

	return Node( nextRed, nextBlue, curr.time + 1 );
}

Position RollLeft( Position target, bool& isEscape ) {
	int currCol;
	for ( currCol = target.col; board[target.row][currCol] != '#'; currCol-- ) {
		if ( board[target.row][currCol] == 'O' ) {
			isEscape = true;
			break;
		}
	}

	return Position( target.row, currCol + 1 );
}

Node TiltLeft( Node curr, int& isEnd ) {
	bool redEscape = false;
	Position nextRed = RollLeft( curr.red, redEscape );

	bool blueEscape = false;
	Position nextBlue = RollLeft( curr.blue, blueEscape );

	if ( blueEscape )
		isEnd = -1;
	else {
		if ( redEscape )
			isEnd = 1;
		else
			isEnd = 0;
	}

	if ( nextRed == nextBlue ) {
		// red is on left side than blue
		if ( curr.red.col < curr.blue.col )
			nextBlue.col++;
		else
			nextRed.col++;
	}

	return Node( nextRed, nextBlue, curr.time + 1 );
}