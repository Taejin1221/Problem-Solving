// LeetCode0792_NumberOfMatchingSubsequences.cpp
// https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		const int DIFF = 'a';

		vector<int> table[26];
		for (int i = 0; i < s.size(); i++)
			table[s[i] - DIFF].push_back(i);

		int indexes[26], ans = 0;
		for (string& word : words) {
			fill(indexes, indexes + 26, 0);

			int prevIdx = -1;
			bool isSubsequence = true;
			for (char& oneChar : word) {
				int charToInt = oneChar - DIFF;
				bool doesStrHaveAlphabet = false;
				while (indexes[charToInt] < table[charToInt].size()) {
					if (table[charToInt][indexes[charToInt]] <= prevIdx)
						indexes[charToInt]++;
					else {
						doesStrHaveAlphabet = true;
						break;
					}
				}

				if (doesStrHaveAlphabet)
					prevIdx = table[charToInt][indexes[charToInt]++];
				else {
					isSubsequence = false;
					break;
				}
			}

			if (isSubsequence)
				ans++;
		}

		return ans;
	}
};