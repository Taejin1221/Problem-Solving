// Baekjoon19947.cpp
// https://www.acmicpc.net/problem/19947
#include <iostream>

using namespace std;

int ans;

void backtracking(int currYear, int currMoney) {
	if (currYear == 0)
		ans = max(ans, currMoney);
	else {
		backtracking(currYear - 1, currMoney + (int)((double)currMoney / 100 * 5));
		if (currYear >= 3)
			backtracking(currYear - 3, currMoney + (int)((double)currMoney / 100 * 20));
		if (currYear >= 5)
			backtracking(currYear - 5, currMoney + (int)((double)currMoney / 100 * 35));
	}
}

int main(void) {
	int h, y;
	cin >> h >> y;

	backtracking(y, h);

	cout << ans << '\n';

	return 0;
}