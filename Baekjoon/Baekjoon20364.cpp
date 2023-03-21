// Baekjoon20364.cpp
// https://www.acmicpc.net/problem/20364
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<bool> owner (n + 1);

	while (q--) {
		int duck, curr;
		cin >> duck;

		int ans = curr = duck;
		while (curr != 1) {
			if (owner[curr])
				ans = curr;
			curr /= 2;
		}

		if (ans == duck && !owner[duck]) {
			owner[duck] = true;
			cout << '0';
		}
		else
			cout << ans;
		cout << '\n';
	}

	return 0;
}