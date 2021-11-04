// Baekjoon10409.cpp
#include <iostream>

using namespace std;

int main(void) {
	int n, t;
	cin >> n >> t;

	int ansSum = 0, ans = 0;
	for (int i = 1; i <= n && ansSum < t; i++) {
		int curr;
		cin >> curr;

		ansSum += curr;
		if (ansSum <= t)
			ans = i;
	}

	cout << ans << '\n';

	return 0;
}