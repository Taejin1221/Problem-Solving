// LeetCode0029_DivideTwoIntegers.cpp
// https://leetcode.com/problems/divide-two-integers/
typedef long long ll;

class Solution {
public:
	int divide( int dividend, int divisor ) {
		ll dend = (ll)dividend, sor = (ll)divisor;

		int negative = false;
		if ( dend < 0 ) {
			dend -= dend + dend;
			negative = !negative;
		}

		if ( sor < 0 ) {
			sor -= sor + sor;
			negative = !negative;
		}

		ll ans = 0;
		if ( sor == 1 )
			ans = dend;
		else if ( dend == sor )
			ans = 1;
		else if ( dend > sor ) {
			map<int, ll> multiTable; // (multiplcator, multiplicand)
			multiTable[0] = 0;
			multiTable[1] = sor;

			int cator = 1, prevCator = 0;
			ll cand = sor;
			while ( dend > cand ) {
				cand += cand;
				prevCator = cator;
				cator += cator;

				multiTable[cator] = cand;
			}

			ll start = prevCator, end = cator;
			while ( start < end - 1 ) {
				ll mid = ( start + end ) / 2;

				ll result = multiTable[start] + multiTable[mid - start];
				multiTable[mid] = result;
				if ( dend < result )
					end = mid;
				else
					start = mid;
			}

			if ( multiTable[end] <= dend )
				ans = (ll)end;
			else
				ans = (ll)start;
		}

		if ( negative )
			ans = -ans;

		if ( ans > INT_MAX || ans < INT_MIN )
			ans = INT_MAX;

		return ans;
	}
};