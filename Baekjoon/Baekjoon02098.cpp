// Baekjoon02098.cpp
// https://www.acmicpc.net/problem/2098
#include <iostream>

#define MAX 65536
#define INF 1'000'000'000

using namespace std;

int n;
int weight[16][16];
int dp[16][MAX];

int solve(int target, int visit) {
	if (dp[target][visit] == -1) {
		dp[target][visit] = INF;
		for (int i = 0; i < n; i++)
			if ((visit & (1 << i)))
				dp[target][visit] = min(dp[target][visit], solve(i, visit - (1 << i)) + weight[i][target]);
	}

	return dp[target][visit];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight[i][j];
			if (i != j && weight[i][j] == 0)
				weight[i][j] = INF;
		}
	}

	int max2N = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + max2N + 1, -1);
		dp[i][0] = weight[0][i];
	}

	int ans = INF;
	ans = min(ans, solve(0, max2N - 1));

	cout << ans << '\n';
}