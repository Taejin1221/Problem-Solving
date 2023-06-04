// Baekjoon11005.cpp
// https://www.acmicpc.net/problem/11005
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

char convert(int n) {
	return (n < 10) ? ('0' + n) : ('A' + (n - 10));
}

int main(void) {
	int n, b;
	cin >> n >> b;

	string ans;

	while (n >= b) {
		int mod = n % b;
		ans.push_back(convert(mod));

		n /= b;
	}
	ans.push_back(convert(n));

	reverse(ans.begin(), ans.end());
	cout << ans << '\n';

	return 0;
}