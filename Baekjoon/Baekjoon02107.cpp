// Baekjoon02107.cpp
// https://www.acmicpc.net/problem/2107
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	pair<int, int> arr[25'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = i + 1; j < n; j++)
			if (arr[j].second < arr[i].second)
				count++;
		ans = max(ans, count);
	}

	cout << ans << '\n';

	return 0;
}