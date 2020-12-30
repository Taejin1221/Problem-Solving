// LeetCode01704_DetermineIfStringHavlesAreAlike.cpp
// https://leetcode.com/problems/determine-if-string-halves-are-alike/
// LeetCode Weekly Contest 221
class Solution {
public:
	bool halvesAreAlike( string s ) {
		int aVowel = 0, bVowel = 0;
		for ( int i = 0; i < s.size() / 2; i++ )
			if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
				aVowel++;
		
		for ( int i = s.size() / 2; i < s.size(); i++ )
			if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
				bVowel++;
		
		return aVowel == bVowel;
	}
};