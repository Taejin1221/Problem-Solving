// LeetCode0791.cpp
// https://leetcode.com/problems/custom-sort-string/
int priority[256];

class Solution {
	static bool compare(char& a, char& b) {
		if (a == 0 || b == 0)
			return true;
		else
			return priority[a] < priority[b];
}
public:
	string customSortString(string order, string str) {
		fill(priority, priority + 256, 255);
		for (int i = 0; i < order.size(); i++)
			priority[order[i]] = i;

		sort(str.begin(), str.end(), compare);

		return str;
	}
};