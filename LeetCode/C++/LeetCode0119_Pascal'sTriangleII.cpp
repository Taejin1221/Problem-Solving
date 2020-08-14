// LeetCode0119_Pascal'sTriangleII.cpp
// https://leetcode.com/problems/pascals-triangle-ii/
// August Leetcoding Challenge Day 12
class Solution {
public:
	vector<int> getRow( int k ) {
		vector<int> pascal;
		pascal.push_back( 1 );

		for ( int i = 1; i <= k; i++ ) {
			int prevVal = pascal[0];
			for ( int j = 1; j < i; j++ ) {
				int temp = pascal[j];
				pascal[j] = prevVal + pascal[j];
				prevVal = temp;
			}
			pascal.push_back( 1 );
		}

		return pascal;
	}
};