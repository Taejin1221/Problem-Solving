// LeetCode0520_DetectCapital.cpp
// https://leetcode.com/problems/detect-capital/
// August LeetCoding Challenge Day 1
class Solution {
public:
	bool detectCapitalUse( string word ) {
		int cap = 0;
		for ( int i = 1; i < word.size(); i++ )
			if ( 'A' <= word[i] && word[i] <= 'Z' )
				cap++;

		if ( 'A' <= word[0] && word[0] <= 'Z' ) {
			if ( cap == 0 || cap == word.size() - 1 )
				return true;
			else
				return false;
		} else {
			if ( cap == 0 )
				return true;
			else
				return false;
		}
	}
};