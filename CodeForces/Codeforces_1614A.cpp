// Codeforces_1614A.cpp
#include <iostream>

#include <algorithm>

using namespace std;

void solveTestCase() {
	int n, l, r, k;
	cin >> n >> l >> r >> k;

	int arr[100];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int ans = 0, currSum = 0;
	for (int i = 0; i < n; i++) {
		if (l <= arr[i] && arr[i] <= r) {
			currSum += arr[i];
			if (currSum > k)
				break;
			ans++;
		}
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
