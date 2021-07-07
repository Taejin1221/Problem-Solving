// LeetCode0342_PowerOfFour.cpp
// https://leetcode.com/problems/power-of-four/
// August Leetcoding Challenge Day 4
class Solution {
public:
	bool isPowerOfFour( int num ) {
		if ( num <= 0 )
			return false;
		else {
			while ( num % 4 == 0 )
				num = num >> 2;
			if ( num == 1 || num == 0 )
				return true;
			else
				return false;
		}
	}
};