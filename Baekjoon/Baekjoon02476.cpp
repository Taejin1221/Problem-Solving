// Baekjoon02476.cpp
// https://www.acmicpc.net/problem/2476
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int result;
		if (a == b && b == c) {
			result = 10000 + a * 1000;
		} else if (a == b || b == c || a == c) {
			if (a == b)
				result = 1000 + a * 100;
			else if (b == c)
				result = 1000 + b * 100;
			else
				result = 1000 + c * 100;
		} else {
			result = 100 * max(a, max(b, c));
		}

		ans = max(ans, result);
	}

	cout << ans << '\n';

	return 0;
}