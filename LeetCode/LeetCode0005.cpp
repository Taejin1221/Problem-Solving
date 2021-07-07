// LeetCode0005_LongestPalindromicSubstring.cpp
// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
	string longestPalindrome( string s ) {
		int startIdx = 0, endIdx = 0, ansSize = 1;

		int n = s.size();
		bool isPaline[1'000][1'000] = { false, };
		for ( int i = 0; i < n; i++ )
			isPaline[i][i] = true;

		for ( int dis = 1; dis < n; dis++ ) {
			for ( int row = 0; row < n - dis; row++ ) {
				int col = row + dis;
				if ( s[row] == s[col] ) {
					isPaline[row][col] = ( dis == 1 || isPaline[row + 1][col - 1] );

					if ( isPaline[row][col] )
						if ( ansSize < ( col - row + 1 ) )
							startIdx = row, endIdx = col, ansSize = ( col - row + 1 );
				}
			}
		}

		int ansIdx = 0;
		char ansStr[1'001] = { 0, };
		for ( int i = startIdx; i <= endIdx; i++ )
			ansStr[ansIdx++] = s[i];

		return string( ansStr );
	}
};