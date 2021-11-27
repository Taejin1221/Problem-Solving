// Baekjoon02108.cpp
// https://www.acmicpc.net/problem/2108
#include <iostream>

#include <cmath>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int maxFrequency = 0;
	int arr[500'000], sum = 0;
	int frequency[10'000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		frequency[arr[i] + 4'000]++;
		maxFrequency = max(frequency[arr[i] + 4'000], maxFrequency);
	}

	cout << round((double)sum / n) << '\n';
	sort(arr, arr + n);
	cout << arr[n / 2] << '\n';

	bool findFirst = false;
	int ans = 0;
	for (int i = 0; i <= 8'001; i++) {
		if (frequency[i] == maxFrequency) {
			if (findFirst) {
				ans = i;
				break;
			} else {
				findFirst = true;
				ans = i;
			}
		}
	}
	cout << ans - 4'000<< '\n';

	cout << arr[n - 1] - arr[0] << '\n';

	return 0;
}