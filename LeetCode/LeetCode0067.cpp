// LeetCode0067_AddBinary.cpp
// https://leetcode.com/problems/add-binary/
class Solution {
public:
	string addBinary(string a, string b) {
		int n = a.size(), m = b.size();
		
		int c[10'002] = { 0, };
		int aIdx = n - 1, bIdx = m - 1, cIdx = 0;
		while ( aIdx >= 0 && bIdx >= 0 )
			c[cIdx++] += a[aIdx--] - '0' + b[bIdx--] - '0';
		
		while ( aIdx >= 0 )
			c[cIdx++] += a[aIdx--] - '0';
		
		while ( bIdx >= 0 )
			c[cIdx++] += b[bIdx--] - '0';
		
		for ( int i = 0; i < cIdx; i++ ) {
			c[i + 1] += c[i] / 2;
			c[i] %= 2;
		}
		
		int cLen;
		if ( c[cIdx] > 0 )
			cLen = cIdx + 1;
		else
			cLen = cIdx;
		
		char ans[10'002] = { 0, };
		for ( int i = 0; i < cLen; i++ )
			ans[i] = (char)c[cLen - i - 1] + '0';
		
		return string( ans );
	}
};