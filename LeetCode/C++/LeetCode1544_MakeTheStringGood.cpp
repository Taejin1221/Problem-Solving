// LeetCode1544_MakeTheStringGood.cpp
// https://leetcode.com/problems/make-the-string-great/
// LeetCode Weekly Contest 201 A
class Solution {
public:
	string makeGood( string s ) {
		int len = s.size();

		for ( int i = 0; i < len - 1; ) {
			if ( abs( s[i] - s[i + 1] ) == 32 ) {
				s.erase( i, 2 );
				len -= 2;
				if ( i != 0 )
					i--;
			} else
				i++;
		}

		return s;
	}
};