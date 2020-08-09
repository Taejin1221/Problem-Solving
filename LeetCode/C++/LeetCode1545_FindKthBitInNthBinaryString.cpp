// LeetCode1545_FindKthBitInNthBinaryString.cpp
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// LeetCode Weekly Contest 201 B
class Solution {
public:
	char findKthBit( int n, int k ) {
		if ( n == 1 )
			return '0';

		int size = ( 1 << n ) - 1;
		if ( k == (size / 2 + 1) )
			return '1';
		else if ( k <= size / 2 )
			return findKthBit( n - 1, k );
		else {
			if ( findKthBit( n - 1, size - k + 1 ) == '0' )
				return '1';
			else
				return '0';
		}
	}
};