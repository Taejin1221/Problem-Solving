// LeetCode0746_MinCostClimbingStairs.cpp
// https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int size = cost.size();
		int minCost[1000] = { cost[0], cost[1], };

		for ( int i = 2; i < cost.size(); i++ )
			minCost[i] = min( minCost[i - 1], minCost[i - 2] ) + cost[i];

		return min( minCost[size - 2], minCost[size - 1] );
	}
};