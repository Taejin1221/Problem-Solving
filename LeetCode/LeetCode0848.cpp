// LeetCode0848.cpp
// https://leetcode.com/problems/shifting-letters/
class Solution {
public:
	string shiftingLetters(string s, vector<int>& shifts) {
		int n = s.size();
		string ans = s;

		int diff = shifts[n - 1];
		for (int i = n - 1; i >= 1; i--) {
			ans[i] = 'a' + (s[i] - 'a' + diff) % 26;
			diff = (shifts[i - 1] + diff) % 26;
		}
		ans[0] = 'a' + (s[0] - 'a' + diff) % 26;

		return ans;
	}
};