// LeetCode1137.cpp
// https://leetcode.com/problems/n-th-tribonacci-number/
class Solution {
public:
	int tribonacci(int n) {
		int dp[38] = { 0, 1, 1, };
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		
		return dp[n];
	}
};