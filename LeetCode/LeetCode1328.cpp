// LeetCode1328.cpp
class Solution {
	bool isPalindrome(string& s) {
		int n = s.size();
		for (int i = 0; i < n / 2; i++)
			if (s[i] != s[n - i - 1])
				return false;

		return true;
	}

	string changeString(string s, int i) {
		if (s[i] == 'a')
			s[i]++;
		else
			s[i] = 'a';

		return s;
	}

public:
	string breakPalindrome(string palindrome) {
		string ans = changeString(palindrome, 0);
		for (int i = 1; i < palindrome.size(); i++) {
			string temp = changeString(palindrome, i);

			if (!isPalindrome(temp))
				ans = (ans > temp) ? temp : ans;
		}

		if (isPalindrome(ans))
			return "";
		else
			return ans;
	}
};