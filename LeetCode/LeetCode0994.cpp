// LeetCode0994_RottingOranges.cpp
// https://leetcode.com/problems/rotting-oranges/
// August Leetcoding Challenge Day 9
struct Position {
	int row, col;
	Position( ): row(0), col(0) {}
	Position( int r, int c ): row(r), col(c) {}
};

class Solution {
private:
	int maxRow, maxCol, num1;

	bool bfs( vector<vector<int>>& grid, queue<Position>& q ) {
		int rottenate = false;
		while ( !q.empty() ) {
			Position currPos = q.front(); q.pop();

			Position surr[4] = {
				Position( currPos.row - 1, currPos.col ),
				Position( currPos.row, currPos.col + 1 ),
				Position( currPos.row, currPos.col - 1 ),
				Position( currPos.row + 1, currPos.col )
			};

			for ( Position& next : surr ) {
				if ( (0 <= next.row && next.row < maxRow) && (0 <= next.col && next.col < maxCol ) ) {
					if ( grid[next.row][next.col] == 1 ) {
						grid[next.row][next.col] = 2;
						rottenate = true;
					}
				}
			}
		}

		return rottenate;
	}

public:
	int orangesRotting( vector<vector<int>>& grid ) {
		maxRow = grid.size();
		maxCol = grid[0].size();

		int time = -1;
		bool visited[10][10] = { false, };

		queue<Position> q;
		do {
			time++;
			for ( int i = 0; i < maxRow; i++ ) {
				for ( int j = 0; j < maxCol; j++ ) {
					if ( grid[i][j] == 2 && !visited[i][j] ) {
						visited[i][j] = true;
						q.push( Position( i, j ) );
					} else if ( grid[i][j] == 1 )
						num1++;
				}
			}
		} while ( bfs( grid, q ) );

		if ( num1 )
			return -1;
		else
			return time;
	}
};