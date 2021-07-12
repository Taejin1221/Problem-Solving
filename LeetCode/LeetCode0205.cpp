// LeetCode0205.cpp
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		char table[128] = { 0, };

		for (int i = 0; i < s.size(); i++) {
			if (table[s[i]] == 0)
				table[s[i]] = t[i];
			else {
				if (table[s[i]] != t[i])
					return false;
			}
		}

		memset(table, 0, 128);

		for (int i = 0; i < t.size(); i++) {
			if (table[t[i]] == 0)
				table[t[i]] = s[i];
			else {
				if (table[t[i]] != s[i])
					return false;
			}
		}

		return true;
	}
};