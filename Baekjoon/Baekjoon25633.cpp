// Baekjoon25633.cpp
// https://www.acmicpc.net/problem/25633
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int domino[1'000];
	for (int i = 0; i < n; i++)
		cin >> domino[i];

	int ans = 1;
	for (int i = 0; i < n; i++) {
		int result = 1, sum = domino[i];
		for (int j = i + 1; j < n; j++) {
			if (sum >= domino[j]) {
				sum += domino[j];
				result++;
			}
		}

		ans = max(ans, result);
	}

	cout << ans << '\n';

	return 0;
}