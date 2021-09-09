// LeetCode0290.cpp
// https://leetcode.com/problems/word-pattern/
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		vector<string> token;
		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				token.push_back(temp);
				temp = "";
			} else
				temp.push_back(s[i]);
		}
		token.push_back(temp);

		if (pattern.size() != token.size())
			return false;
		else {
			map<char, string> table1;
			map<string, char> table2;

			for (int i = 0; i < pattern.size(); i++) {
				auto find1 = table1.find(pattern[i]);
				auto find2 = table2.find(token[i]);

				if (find1 == table1.end() && find2 == table2.end()) {
					table1.insert({ pattern[i], token[i] });
					table2.insert({ token[i], pattern[i] });
				} else if (find1 != table1.end() && find2 != table2.end()) {
					if (find1->second != token[i] || find2->second != pattern[i])
						return false;
				} else
					return false;
			}

			return true;
		}
	}
};