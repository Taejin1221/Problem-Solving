// LeetCode0119_Pascal'sTriangleII.cpp
// https://leetcode.com/problems/pascals-triangle-ii/
// August Leetcoding Challenge Day 12
class Solution {
public:
	vector<int> getRow( int k ) {
		vector<int> pascal;
		pascal.push_back( 1 );

		for ( int i = 1; i <= k; i++ ) {
			for ( int j = i - 1; j > 0; j-- )
				pascal[j] = pascal[j - 1] + pascal[j];
			pascal.push_back( 1 );
		}

		return pascal;
	}
};