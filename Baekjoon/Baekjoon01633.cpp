// Baekjoon01633.cpp
// https://www.acmicpc.net/problem/1633
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int n;
pii players[1'000];
int dp[1'000][16][16];

int solve(int i, int white, int black) {
	if (i == n)
		return 0;

	int& data = dp[i][white][black];
	if (data == -1) {
		int ans = 0;
		if (white > 0)
			ans = max(ans, solve(i + 1, white - 1, black) + players[i].first);
		if (black > 0)
			ans = max(ans, solve(i + 1, white, black - 1) + players[i].second);
		ans = max(ans, solve(i + 1, white, black));

		data = ans;
	}

	return data;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (n = 0; !cin.eof(); n++)
		cin >> players[n].first >> players[n].second;

	fill(&dp[0][0][0], &dp[999][15][16], -1);

	cout << solve(0, 15, 15) << endl;

	return 0;
}