// Baekjoon12026.cpp
// https://www.acmicpc.net/problem/12026
#include <iostream>

#include <string>

#define INF 1'234'567'890

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string str;
	cin >> str;

	int dp[1'000];
	fill(dp, dp + n, INF);

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		char target;
		if (str[i] == 'B') target = 'J';
		else if (str[i] == 'O') target = 'B';
		else target = 'O';

		for (int j = i - 1; j >= 0; j--)
			if (str[j] == target)
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
	}

	if (dp[n - 1] == INF)
		cout << -1;
	else
		cout << dp[n - 1];
	cout << '\n';

	return 0;
}