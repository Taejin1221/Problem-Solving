// Baekjoon01940.cpp
// https://www.acmicpc.net/problem/1940
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[15'000];
	bool table[100'001] = { false, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		table[arr[i]] = true;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i];
		int diff = m - val;
		if ((0 < diff && diff <= 100'000) && val != diff && table[val] && table[diff]) {
			ans++;
			table[val] = false, table[diff] = false;
		}
	}

	cout << ans << '\n';

	return 0;
}