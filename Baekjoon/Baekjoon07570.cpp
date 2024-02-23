// Baekjoon07570.cpp
// https://www.acmicpc.net/problem/7570
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int numPosition[1'000'001];
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		numPosition[num] = i;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int curr = 1;
		while (i <= n && numPosition[i] < numPosition[i + 1])
			curr++, i++;

		ans = max(ans, curr);
	}

	cout << n - ans << '\n';

	return 0;
}