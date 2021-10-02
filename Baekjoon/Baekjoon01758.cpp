// Baekjoon01758.cpp
// https://www.acmicpc.net/problem/1758
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[100'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long value = arr[n - i - 1] - i;
		ans += value > 0 ? value : 0;
		// cout << ans << endl;
	}

	cout << ans << '\n';

	return 0;
}