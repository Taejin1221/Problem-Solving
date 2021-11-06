// Baekjoon02546.cpp
// https://www.acmicpc.net/problem/2546
#include <iostream>

using namespace std;

using ll = long long;
using ld = long double;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int arr1[200'000];
		ll cSum = 0LL, eSum = 0LL;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
			cSum += arr1[i];
		}

		int arr2[200'000];
		for (int j = 0; j < m; j++) {
			cin >> arr2[j];
			eSum += arr2[j];
		}

		int ans = 0;
		ld cAverage = (ld)cSum / n, eAverage = (ld)eSum / m;
		for (int i = 0; i < n; i++) {
			if (arr1[i] < cAverage && arr1[i] > eAverage)
				ans ++;
		}

		cout << ans << '\n';
	}

	return 0;
}