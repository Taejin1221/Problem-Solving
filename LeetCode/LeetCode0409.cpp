// LeetCode0409_LongestPalindrome.cpp
// https://leetcode.com/problems/longest-palindrome/
// August Leetcoding Challenge Day 14
class Solution {
public:
	int longestPalindrome( string s ) {
		map<char, int> table;

		for ( char& c : s ) {
			if ( table[c] )
				table[c]++;
			else
				table[c] = 1;
		}

		int even = 0, odd = 0;
		for ( auto iter = table.begin(); iter != table.end(); ++iter ) {
			if ( iter->second % 2 ) {
				odd++;
				even += iter->second - 1;
			} else
				even += iter->second;
		}

		return even + ( odd > 1 ? 1 : odd );
	}
};