// Baekjoon25592.cpp
// https://www.acmicpc.net/problem/25592
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ans;
	for (int i = 1; ; i += 2) {
		int a = i * (i + 1) / 2;
		int b = (i + 1) * (i + 2) / 2 - 1;

		if (a <= n && n <= b) {
			ans = 0;
			break;
		} else if (n < a) {
			ans = a - n;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}