// LeetCode0171_ExcelSheetColumnNumber.cpp
// https://leetcode.com/problems/excel-sheet-column-number/
// August Leetcoding Challenge Day 10
class Solution {
public:
	int titleToNumber( string s ) {
		const int diff = 'A' - 1;
		int ans = 0;
		for ( int idx = 0, exp = s.size() - 1; exp >= 0; idx++, exp-- )
			ans += pow( 26, exp ) * (s[idx] - diff);
		return ans;
	}
};