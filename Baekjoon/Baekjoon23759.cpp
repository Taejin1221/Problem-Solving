// Baekjoon23759.cpp
// https://www.acmicpc.net/problem/23759
#include <iostream>

#include <string>
#include <algorithm>

#ifdef ONLINE_JUDGE
#define MAX 500'000
#else
#define MAX 500
#endif
#define INF 0x3f3f3f3f

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string strs[MAX];
	for (int i = 0; i < n; i++)
		cin >> strs[i];

	int dp[MAX];
	fill(dp, dp + n, INF);

	int position[10][26];
	fill(&position[0][0], &position[9][26], -1);

	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int charPosition = position[j][strs[i][j] - 'a'];
			if (charPosition == -1)
				dp[i] = min(dp[i], i);
			else
				dp[i] = min(dp[i], dp[charPosition] + i - charPosition - 1);
			position[j][strs[i][j] - 'a'] = i;
		}
		ans = min(ans, dp[i] + n - i - 1);
	}

	cout << ans << '\n';

	return 0;
}