// LeetCode0200_NumberOfIslands.cpp
#define VISIT 1
#define UNVISIT 0

typedef struct _Position {
	int row;
	int col;
} Position;

class Solution {
public:
	int rowSize, colSize;
	vector<vector<int>> visited;

	void BFS(vector<vector<char>>& grid, Position target) {
		queue<Position> q;

		q.push(target);
		while (! q.empty()) {
			Position curr = q.front(); q.pop();

			Position surr[4] = {
				{ curr.row - 1, curr.col }, // Up
				{ curr.row, curr.col + 1 }, // Right
				{ curr.row + 1, curr.col }, // Down
				{ curr.row, curr.col - 1 }  // Left
			};

			for (int i = 0; i < 4; i++) {
				int currRow = surr[i].row, currCol = surr[i].col;
				if ((currRow >= 0 && currCol >= 0) && (currRow < rowSize && currCol < colSize))
					if ( visited[currRow][currCol] == UNVISIT ) {
						visited[currRow][currCol] = VISIT;
						if ( grid[currRow][currCol] == '1' )
							q.push( { currRow, currCol } );
					}
			}			
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0) return 0;
		rowSize = grid.size();
		colSize = grid[0].size();

		visited = vector<vector<int>> (rowSize, vector<int> (colSize));

		int count = 0;

		for (int i = 0; i < rowSize; i++)
			for (int j = 0; j < colSize; j++)
				if (visited[i][j] == UNVISIT) {
					visited[i][j] = VISIT;
					if (grid[i][j] == '1') {
						BFS(grid, { i, j });
						count++;
					}
				}

		return count;
	}
};
