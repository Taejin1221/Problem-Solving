// LeetCode0695_MaxAreaOfIsland.cpp
// https://leetcode.com/problems/max-area-of-island/
const int rowChange[4] = { -1, 0, 0, 1 }, colChange[4] = { 0, -1, 1, 0 };

class Solution {
public:
	int maxAreaOfIsland( vector<vector<int>>& grid ) {
		int maxRow = grid.size(), maxCol = grid[0].size();

		int ans = 0;
		bool visited[50][50] = { false, };
		for ( int i = 0; i < maxRow; i++ ) {
			for ( int j = 0; j < maxCol; j++ ) {
				if ( !visited[i][j] && grid[i][j] ) {
					int currIsland = 1;

					queue<pair<int, int>> q;
					q.push( { i, j } );

					visited[i][j] = true;
					while ( !q.empty() ) {
						pair<int, int> curr = q.front(); q.pop();

						for ( int i = 0; i < 4; i++) {
							int newRow = curr.first + rowChange[i], newCol = curr.second + colChange[i];
							if ( ( 0 <= newRow && newRow < maxRow ) && ( 0 <= newCol && newCol < maxCol ) ) {
								if ( !visited[newRow][newCol] && grid[newRow][newCol] ) {
									visited[newRow][newCol] = true;
									q.push( { newRow, newCol } );

									currIsland++;
								}
							}
						}
					}

					ans = max( ans, currIsland );
				}
			}
		}

		return ans;
	}
};