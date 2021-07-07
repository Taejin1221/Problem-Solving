// Baekjoon11585_TiredDinnerMenu.cpp
// https://www.acmicpc.net/problem/11585
#include <iostream>

#include <cstring>

using namespace std;

int GCD(int a, int b) {
	return (b != 0? GCD(b, a % b) : a);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char meat[1'000'001] = { 0, }, roulette[2'000'001] = { 0, };
	for (int i = 0; i < n; i++)
		cin >> meat[i];

	for (int i = 0; i < n; i++) {
		cin >> roulette[i];
		roulette[n + i] = roulette[i];
	}

	int fail[1'000'000] = { 0, };
	for (int i = 1, j = 0; i < n; i++) {
		while (j != 0 && meat[i] != meat[j])
			j = fail[j - 1];

		if (meat[i] == meat[j])
			fail[i] = ++j;
	}

	int ans = 0;
	for (int i = 0, j = 0; i < 2 * n; i++) {
		while (j != 0 && roulette[i] != meat[j])
			j = fail[j - 1];

		if (roulette[i] == meat[j]) {
			if (j == n - 1) {
				ans++;
				j = fail[j];
			} else
				j++;
		}
	}

	if (strncmp(meat, roulette, n) == 0)
		ans--;

	int gcd = GCD(n, ans);
	cout << ans / gcd << '/' << n / gcd << '\n';

	return 0;
}