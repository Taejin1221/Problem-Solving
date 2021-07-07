// LeetCode0980_UniquePathsIII.cpp
// https://leetcode.com/problems/unique-paths-iii/
struct Position {
	int row, col;
	Position( ): row(0), col(0) {}
	Position( int row, int col ): row(row), col(col) {}
};

class Solution {
private:
	int ans;
	int maxRow, maxCol;
	void dfs( vector<vector<int>>& grid, vector<vector<bool>>& visited, Position curr, int size ) {
		if ( grid[curr.row][curr.col] == 2 && size == 0 )
			ans++;
		else {
			Position nexts[4] = {
				Position( curr.row - 1, curr.col ), Position( curr.row, curr.col + 1 ),
				Position( curr.row + 1, curr.col ), Position( curr.row, curr.col - 1 )
			};

			for ( Position& next : nexts ) {
				int row = next.row, col = next.col;
				if ( ( 0 <= row && row < maxRow ) && ( 0 <= col && col < maxCol ) ) {
					if ( !visited[row][col] ) {
						visited[row][col] = true;
						dfs( grid, visited, next, size - 1 );
						visited[row][col] = false;
					}
				}
			}
		}
	}

public:
	int uniquePathsIII( vector<vector<int>>& grid ) {
		maxRow = grid.size(), maxCol = grid[0].size();
		int size = maxRow * maxCol - 1;

		vector<vector<bool>> visited;
		for ( int i = 0; i < maxRow; i++ )
			visited.push_back( vector<bool> ( maxCol ) );

		Position start;
		for ( int i = 0; i < maxRow; i++ ) {
			for ( int j = 0; j < maxCol; j++ ) {
				if ( grid[i][j] == 1 ) {
					visited[i][j] = true;
					start.row = i, start.col = j;
				} else if ( grid[i][j] == -1 ) {
					visited[i][j] = true;
					size--;
				}
			}
		}

		ans = 0;
		dfs( grid, visited, start, size );

		return ans;
	}
};