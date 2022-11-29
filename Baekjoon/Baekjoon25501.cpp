// Baekjoon25501.cpp
// https://www.acmicpc.net/problem/25501
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;

		int ans = 0;
		bool isPalindrome = true;

		for (int i = 0, j = str.size() - 1; ; i++, j--) {
			ans++;
			if (i >= j)
				break;

			if (str[i] != str[j]) {
				isPalindrome = false;
				break;
			}
		}

		cout << isPalindrome << ' ' << ans << '\n';
	}

	return 0;
}