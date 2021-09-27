// Baekjoon03986.cpp
// https://www.acmicpc.net/problem/3986
#include <iostream>

#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0;
	while (n--) {
		string str;
		cin >> str;

		stack<char> stck;
		for (int i = 0; i < str.size(); i++) {
			if (!stck.empty()) {
				if (stck.top() == str[i])
					stck.pop();
				else
					stck.push(str[i]);
			} else
				stck.push(str[i]);
		}

		if (stck.empty())
			ans++;
	}

	cout << ans << '\n';

	return 0;
}