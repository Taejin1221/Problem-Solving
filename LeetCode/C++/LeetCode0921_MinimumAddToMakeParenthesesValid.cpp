// LeetCode0921_MinimumAddToMakeParenthesesValid.cpp
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
class Solution {
public:
	int minAddToMakeValid( string s ) {
		vector<char> v;

		for ( char& c : s ) {
			if ( v.size() == 0 ) {
				v.push_back( c );
				continue;
			}
			if ( c == '(' )
				v.push_back( c );
			else {
				if ( v[v.size() - 1] == '(' )
					v.pop_back();
				else
					v.push_back( c );
			}
		}

		return v.size();
	}
};