// LeetCode1953.cpp
// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
class Solution {
public:
	long long numberOfWeeks(vector<int>& milestones) {
		long long maxVal = 0ll, sum = 0ll;
		for (int i = 0; i < milestones.size(); i++) {
			sum += milestones[i];
			maxVal = max(maxVal, (long long)milestones[i]);
		}
		sum -= maxVal;

		return sum + min(maxVal, sum + 1);
	}
};