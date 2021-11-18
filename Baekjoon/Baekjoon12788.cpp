// Baekjoon12788.cpp
// https://www.acmicpc.net/problem/12788
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int m, k;
	cin >> m >> k;

	int total = m * k;

	int arr[1'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		total -= arr[i];
		ans++;
		if (total <= 0)
			break;
	}

	if (total > 0)
		cout << "STRESS" << endl;
	else
		cout << ans << '\n';

	return 0;
}