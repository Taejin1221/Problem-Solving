// LeetCode0977_SquaresOfASortedArray.cpp
// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
	vector<int> sortedSquares( vector<int>& A ) {
		vector<int> ans;
		for ( int i = 0; i < A.size(); i++ )
			ans.push_back( A[i] * A[i] );

		for ( int i = 1; i < ans.size(); i++ ) {
			int j, value = ans[i];
			for ( j = i - 1; (j >= 0) && (ans[j] > value); j-- )
				ans[j + 1] = ans[j];
			ans[j + 1] = value;
		}

		// sort( ans.begin(), ans.end() );

		return ans;
	}
};