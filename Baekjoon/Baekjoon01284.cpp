// Baekjoon01284.cpp
// https://www.acmicpc.net/problem/1284
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string n;
	cin >> n;
	while (n != "0") {
		int ans = 1;

		for (int i = 0; i < n.size(); i++) {
			if (n[i] == '1') {
				ans += 2;
			} else if (n[i] == '0') {
				ans += 4;
			} else {
				ans += 3;
			}
			ans++;
		}

		cout << ans << '\n';

		cin >> n;
	}

	return 0;
}