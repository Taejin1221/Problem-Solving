// LeetCode0566_ReshapeTheMatrix.cpp
// https://leetcode.com/problems/reshape-the-matrix/
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int n = mat.size(), m = mat[0].size();
		if (r * c != n * m)
			return mat;

		int rIdx = 0, cIdx = 0;
		vector<vector<int>> ans(r, vector<int> (c));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans[rIdx][cIdx++] = mat[i][j];
				rIdx += cIdx / c;
				cIdx %= c;
			}
		}

		return ans;
	}
};