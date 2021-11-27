// Baekjoon23756.cpp
// https://www.acmicpc.net/problem/23756
// KCPC 2021 Div. 2 A
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = 0, currPos;
	cin >> currPos;
	for (int i = 0; i < n; i++) {
		int nextPos;
		cin >> nextPos;

		int diff = abs(currPos - nextPos);
		ans += min(diff, 360 - diff);
		currPos = nextPos;
	}

	cout << ans << '\n';

	return 0;
}