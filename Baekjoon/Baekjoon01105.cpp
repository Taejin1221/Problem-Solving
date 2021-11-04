// Baekjoon01105.cpp
// https://www.acmicpc.net/problem/1105
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string l, r;
	cin >> l >> r;

	if (l.size() != r.size())
		cout << 0;
	else {
		int ans = 0;
		for (int i = 0; i < (int)l.size() && l[i] == r[i]; i++)
			if (l[i] == '8')
				ans++;

		cout << ans;
	}
	cout << '\n';

	return 0;
}