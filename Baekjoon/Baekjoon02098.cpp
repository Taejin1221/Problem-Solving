// Baekjoon02098.cpp
// https://www.acmicpc.net/problem/2098
#include <iostream>

#define MAX 65536
#define INF 1'000'000'000

using namespace std;

int n;
int weight[16][16];
int dp[16][16][MAX];

int solve(int start, int target, int visit) {
	if (dp[start][target][visit] == -1) {
		dp[start][target][visit] = INF;
		for (int i = 0; i < n; i++)
			if ((visit & (1 << i)))
				dp[start][target][visit] = min(dp[start][target][visit], solve(start, i, visit - (1 << i)) + weight[i][target]);
	}

	return dp[start][target][visit];
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
		for (int j = 0; j < n; j++){
			fill(dp[i][j], dp[i][j] + max2N + 1, -1);
			dp[i][j][0] = weight[i][j];
		}
	}

	int ans = INF;
	for (int i = 0; i < n; i++)
		ans = min(ans, solve(i, i, max2N - (1 << i)));

	cout << ans << '\n';
}