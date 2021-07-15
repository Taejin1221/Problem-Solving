// Baekjoon02437.cpp
// https://www.acmicpc.net/problem/2437
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int ans = -1, sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < arr[i]) {
			ans = sum + 1;
			break;
		}

		sum += arr[i];
	}

	if (ans == -1)
		ans = sum + 1;

	cout << ans << '\n';

	return 0;
}