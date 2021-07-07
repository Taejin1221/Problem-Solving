// Baekjoon02482.cpp
// https://www.acmicpc.net/problem/2482
#include <iostream>

#define MOD 1'000'000'003

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	long long dp[1'001][1'001] = { 0, };
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= (i + 1) / 2; j++) {
			if (j == 0)
				dp[i][j] = 1;
			else if (j == 1)
				dp[i][j] = i;
			else
				dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}

	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % MOD << '\n';

	return 0;
}