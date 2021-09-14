// LeetCode0917.cpp
// https://leetcode.com/problems/reverse-only-letters/
#define NOT_ALPHABET(x) !(('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z'))
#define IS_ALPHABET(x) ('A' <= x && x <= 'Z') || ('a' <= x && x <= 'z')

class Solution {
public:
	string reverseOnlyLetters(string s) {
		char ans[101] = { 0, };
		for (int i = 0; i < s.size(); i++) {
			if (NOT_ALPHABET(s[i]))
				ans[i] = s[i];
		}

		int idx = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			while (ans[idx] != 0 && NOT_ALPHABET(ans[idx]))
				idx++;

			if (IS_ALPHABET(s[i]))
				ans[idx++] = s[i];
		}

		return string(ans);
	}
};