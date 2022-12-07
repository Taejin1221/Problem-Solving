// Baekjoon15961.cpp
// https://www.acmicpc.net/problem/15961
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	int sushi[6'000'000];
	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
		sushi[i + n] = sushi[i];
	}

	int ans = 0;
	int select[3'001] = { 0, };

	int currType = 0;
	for (int i = 0, j = 0; i < n; j++) {
		if (select[sushi[j]]++ == 0)
			currType++;

		if (j - i + 1 > k) {
			if (--select[sushi[i++]] == 0)
				currType--;
		}

		ans = max(ans, currType + (select[c] == 0 ? 1 : 0));
	}

	cout << ans << '\n';
}