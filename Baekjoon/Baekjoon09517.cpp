// Baekjoon09517.cpp
// https://www.acmicpc.net/problem/9517
#include <iostream>

using namespace std;

int main(void) {
	int ans;
	cin >> ans;

	int n;
	cin >> n;

	int target = 210;
	for (int i = 0; i < n; i++) {
		int second; char a;
		cin >> second >> a;

		target -= second;
		if (target <= 0) {
			cout << ans << '\n';
			break;
		}

		if (a == 'T') {
			if (ans == 8)
				ans = 1;
			else
				ans++;
		}
	}

	return 0;
}