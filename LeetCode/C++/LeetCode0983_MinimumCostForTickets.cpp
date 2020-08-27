// LeetCode0983_MinimumCostForTickets.cpp
class Solution {
public:
	int mincostTickets( vector<int>& days, vector<int>& costs ) {
		int maxDay = days[days.size() - 1];

		vector<int> dp( maxDay + 1 );

		int idx = 0, currDay = 1;
		while ( idx < days.size() ) {
			if ( currDay != days[idx] )
				dp[currDay] = dp[currDay - 1];
			else {
				dp[currDay] = dp[currDay - 1] + costs[0];
				idx++;
			}

			if ( currDay >= 7 )
				dp[currDay] = min( dp[currDay], dp[currDay - 7] + costs[1] );

			if ( currDay >= 30 )
				dp[currDay] = min( dp[currDay], dp[currDay - 30] + costs[2] );
			currDay++;
		}

		return dp[maxDay];
	}
};