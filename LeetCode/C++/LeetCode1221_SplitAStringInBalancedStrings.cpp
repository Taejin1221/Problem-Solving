// LeetCode1221_SplitAStringInBalancedStrings.cpp
// https://leetcode.com/problems/split-a-string-in-balanced-strings/
class Solution {
public:
	int balancedStringSplit( string s ) {
		int ans = 0, temp = 0;

		for ( char& c : s ) {
			if ( c == 'R' )
				temp++;
			else
				temp--;

			if ( !temp )
				ans++;
		}

		return ans;
	}
};