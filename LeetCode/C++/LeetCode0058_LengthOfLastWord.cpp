// LeetCode0058_LengthOfLastWord.cpp
// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
	int lengthOfLastWord( string s ) {
		int i;
		for ( i = s.size() - 1; i >= 0 && s[i] == ' '; i-- );

		int ans = 0;
		for ( ; i >= 0 && s[i] != ' '; i-- )
			ans++;

		return ans;
	}
};