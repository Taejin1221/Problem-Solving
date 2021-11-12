// Baekjoon01703.cpp
// https://www.acmicpc.net/problem/1703
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	while (n) {
		int ans = 1;
		for (int i = 0; i < n; i++) {
			int factor, cut;
			cin >> factor >> cut;

			ans *= factor;
			ans -= cut;
		}

		cout << ans << '\n';

		cin >> n;
	}

	return 0;
}