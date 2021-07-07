// LeetCode1599_MaximumProfitOfOperatingACentennialWheel.cpp
// https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/
struct Info {
	int profit, times;
	Info( ): profit(0), times(0) {}
	Info( int p, int t ): profit(p), times(t) {}
};

class Solution {
public:
	int minOperationsMaxProfit( vector<int>& customers, int boardingCost, int runningCost ) {
		int idx = 1, size = customers.size();

		int waits = customers[0];
		Info curr = Info(), ans = Info( 0, -1 );
		while ( waits > 0 || idx < size ) {
			if ( waits > 4 ) {
				curr.profit += 4 * boardingCost;
				waits -= 4;
			} else {
				curr.profit += waits * boardingCost;
				waits = 0;
			}

			curr.profit -= runningCost;
			curr.times++;
			if ( curr.profit > ans.profit )
				ans = curr;

			if ( idx < size )
				waits += customers[idx++];
		}

		return ans.times;
	}
};