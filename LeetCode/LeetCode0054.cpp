// LeetCode0054_SpiralMatrix.cpp
// https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
	vector<int> spiralOrder( vector<vector<int>>& matrix ) {
		int rowSize = matrix.size(), colSize = matrix[0].size();

		int ansIdx = 0;
		vector<int> ans ( rowSize * colSize );

		int num = 0, type = 1;
		int rowIdx = 0, colIdx = 0;
		int rowStart = 1, rowEnd = rowSize - 1;
		int colStart = 0, colEnd = colSize - 1;
		while ( num < rowSize * colSize ) {
			ans[ansIdx++] = matrix[rowIdx][colIdx];

			if ( type == 1 ) {
				if ( colIdx == colEnd ) {
					rowIdx++;
					colEnd--;
					type++;
				} else
					colIdx++;
			} else if ( type == 2 ) {
				if ( rowIdx == rowEnd ) {
					colIdx--;
					rowEnd--;
					type++;
				} else
					rowIdx++;
			} else if ( type == 3 ) {
				if ( colIdx == colStart ) {
					rowIdx--;
					colStart++;
					type++;
				} else
					colIdx--;
			} else if ( type == 4 ) {
				if ( rowIdx == rowStart ) {
					colIdx++;
					rowStart++;
					type = 1;
				} else
					rowIdx--;
			}
			num++;
		}

		return ans;
	}
};