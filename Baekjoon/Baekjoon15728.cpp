// Baekjoon15728.cpp
// https://www.acmicpc.net/problem/15728
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	int n, K;
	cin >> n >> K;

	int share[100], team[100];
	for (int i = 0; i < n; i++) cin >> share[i];
	for (int i = 0; i < n; i++) cin >> team[i];

	int ans = 0;
	bool isDelete[100] = { false, };
	for (int k = 0; k <= K; k++) {
		pii maxInfo = { 0, -1'000'000'000 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!isDelete[j] && maxInfo.second < share[i] * team[j])
					maxInfo = { j, share[i] * team[j] };
			}
		}

		if (k == K)
			ans = maxInfo.second;
		isDelete[maxInfo.first] = true;
	}

	cout << ans << '\n';

	return 0;
}