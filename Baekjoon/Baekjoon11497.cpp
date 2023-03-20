// Baekjoon11497.cpp
// https://www.acmicpc.net/problem/11497
#include <iostream>

#include <vector>
#include <algorithm>

#define ans(a) (a) < 0 ? (-(a)) : (a)

using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<int> ansArr(n);
	ansArr[0] = arr[0];

	for (int i = 1, j = n - 1, k = 1; k < n; i++, j--, k += 2) {
		ansArr[i] = arr[k];
		if (k + 1 < n)
			ansArr[j] = arr[k + 1];
	}

	int ans = abs(ansArr.back() - ansArr[0]);
	for (int i = 0; i < n - 1; i++)
		ans = max(ans, abs(ansArr[i] - ansArr[i + 1]));

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}