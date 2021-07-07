// LeetCode1582_SpecialPositionsInBinaryMatrix.cpp
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/
// LeetCode Weekly Contest 206
class Solution {
private:
	bool isSpecial( vector<vector<int>>& mat, int r, int c ) {
		for ( int i = 0; i < mat.size(); i++ )
			if ( i != r && mat[i][c] == 1 )
				return false;

		for ( int i = 0; i < mat[0].size(); i++ )
			if ( i != c && mat[r][i] == 1 )
				return false;

		return true;
	}

public:
	int numSpecial( vector<vector<int>>& mat ) {
		int ans = 0;
		for ( int i = 0; i < mat.size(); i++ ) {
			for ( int j = 0; j < mat[0].size(); j++ ) {
				if ( mat[i][j] == 1 && isSpecial( mat, i, j ) )
					ans++;
			}
		}

		return ans;
	}
};