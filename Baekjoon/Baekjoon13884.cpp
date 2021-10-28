// Baekjoon13884.cpp
// https://www.acmicpc.net/problem/13884
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int num, n;
		cin >> num >> n;

		int arr[1'000], sortedArr[1'000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sortedArr[i] = arr[i];
		}

		sort(sortedArr, sortedArr + n);

		int ans = 0;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (sortedArr[j] == arr[i]) {
				ans++;
				j++;
			}
		}

		cout << num << ' ' << n - ans << '\n';
	}

	return 0;
}