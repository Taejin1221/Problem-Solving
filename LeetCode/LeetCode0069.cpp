// LeetCode0069_Sqrtx.cpp
// https://leetcode.com/problems/sqrtx/
class Solution {
public:
	int mySqrt(int target) {
		if ( target == 0 )
			return 0;
		
		if ( target <= 3 )
			return 1;

		int start = 0, end = 100'000;
		while ( start < end ) {
			int mid = ( start + end ) / 2;
			
			long long square = (long long)mid * mid;
			if ( square <= target )
				start = mid + 1;
			else
				end = mid - 1;
		}

		long long square = (long long) start * start;
		if ( square <= target )
			return start;
		else
			return start - 1;
	}
};