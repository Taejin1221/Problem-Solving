// LeetCode0392_IsSubsequence.cpp
// https://leetcode.com/problems/is-subsequence/
class Solution {
private:
	bool isSubsequence( string& s, string& t, int idx1, int idx2 ) {
		if ( s.size() == idx1 )
			return true;
		else if ( s.size() != idx1 && t.size() == idx2 )
			return false;
		else {
			if ( s[idx1] == t[idx2] )
				return isSubsequence( s, t, idx1 + 1, idx2 + 1 );
			else
				return isSubsequence( s, t, idx1, idx2 + 1 );
		}
	}

public:
	bool isSubsequence( string s, string t ) {
		return isSubsequence( s, t, 0, 0 );
	}
};