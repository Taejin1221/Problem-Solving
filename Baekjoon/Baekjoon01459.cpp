// Baekjoon01459.cpp
// https://www.acmicpc.net/problem/1459
#include <iostream>

using namespace std;

int main(void) {
	long long x, y, oneBlock, diagonal;
	cin >> x >> y >> oneBlock >> diagonal;

	long long ans;
	if (diagonal < oneBlock * 2) {
		int minPos = min(x, y);
		ans = diagonal * minPos;

		int remain = x - minPos + y - minPos;
		if (diagonal * 2 < oneBlock * 2) {
			ans += diagonal * (remain / 2 * 2);
			remain %= 2;
		}

		ans += remain * oneBlock;
	} else {
		ans = oneBlock * (x + y);
	}

	cout << ans << '\n';

	return 0;
}