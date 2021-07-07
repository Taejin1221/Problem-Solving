// LeetCode1688_CountOfMatchesInTournament.cpp
// https://leetcode.com/problems/count-of-matches-in-tournament/
// LeetCode Weekly Contest 219 A
class Solution {
public:
	int numberOfMatches( int n ) {
		int count = 0;
		while ( n != 1 ) {
			if ( n % 2 ) {
				count += ( n - 1 ) / 2;
				n = ( n - 1 ) / 2 + 1;
			} else {
				count += n / 2;
				n = n / 2;
			}
		}

		return count;
	}
};
