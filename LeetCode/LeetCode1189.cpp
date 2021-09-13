// LeetCode1189.cpp
// https://leetcode.com/problems/maximum-number-of-balloons/
class Solution {
public:
	int maxNumberOfBalloons(string text) {
		map<char, int> table;
		for (char& ch : text) {
			if ('b' == ch)
				table['b']++;
			else if ('a' ==  ch)
				table['a']++;
			else if ('l' == ch)
				table['l']++;
			else if ('o' == ch)
				table['o']++;
			else if ('n' == ch)
				table['n']++;
		}

		int ans = 0;
		while (table['b'] >= 1 && table['a'] >= 1 && table['l'] >= 2 && table['o'] >= 2 && table['n'] >= 1)
				table['b']--, table['a']--, table['l'] -= 2, table['o'] -= 2, table['n']--, ans++;

			return ans;
	}
};