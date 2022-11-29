// BOJ_01495.cpp
// https://www.acmicpc.net/problem/1495
#include <iostream>

#include <algorithm>

using namespace std;

int n, m, ans = -1;
int volumes[50];
bool dp[51][1'001];

void solve(int i, int curr) {
	if (!dp[i][curr]) {
		// cout << i << ' ' << curr << '\n';
		dp[i][curr] = true;
		if (i == n) {
			ans = max(ans, curr);
		} else {
			if (curr - volumes[i] >= 0)
				solve(i + 1, curr - volumes[i]);
			if (curr + volumes[i] <= m)
				solve(i + 1, curr + volumes[i]);
		}
	}
}

int main(void) {
	int s;
	cin >> n >> s >> m;

	for (int i = 0; i < n; i++) {
		cin >> volumes[i];
		fill(dp[i], dp[i] + 1'001, false);
	}
	fill(dp[n], dp[n] + 1'001, false);

	solve(0, s);

	cout << ans << '\n';

	return 0;
}