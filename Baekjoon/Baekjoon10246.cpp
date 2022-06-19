// Baekjoon10246.cpp
// https://www.acmicpc.net/problem/10246
#include <iostream>

using namespace std;

int table[1'000'001];

void solve() {
	for (int res = 2; res <= 1'000'000; res++) {
		int currRes = res;
		for (int i = currRes + 1; currRes <= 1'000'000; i++) {
			table[currRes]++;
			currRes += i;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

	int n;
	cin >> n;
	while (n) {
		cout << table[n] << '\n';

		cin >> n;
	}

	return 0;
}