// LeetCode0899.cpp
// https://leetcode.com/problems/orderly-queue/
class Solution {
public:
	string orderlyQueue(string s, int k) {
		if (k >= 2) {
			sort(s.begin(), s.end());

			return s;
		} else {
			int n = s.size();
			string concat = s + s;

			char ans[1'001] = { 0, };
			s.copy(ans, n, 0);
			for (int i = 1; i < n; i++) {
				char temp[1'001] = { 0, };
				concat.copy(temp, n, i);

				if (strcmp(temp, ans) < 0)
					strcpy(ans, temp);
			}

			return string(ans);
		}
	}
};