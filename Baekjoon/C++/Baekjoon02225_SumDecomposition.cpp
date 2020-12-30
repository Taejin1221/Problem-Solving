// Baekjoon02225_SumDecomposition.cpp
// https://www.acmicpc.net/problem/2225
#include <iostream>

#define MOD 1'000'000'000

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	long long dp[201][201] = { 0LL, };
	for ( int i = 1; i <= K; i++ )
		dp[0][i] = 1;

	// Method 1: Sum of All
	for ( int i = 1; i <= N; i++ ) {
		dp[i][1] = 1;
		for ( int j = 2; j <= K; j++ )
			for ( int k = 0; k <= i; k++ )
				dp[i][j] =  (dp[i][j] + dp[k][j - 1]) % MOD;
	}

	cout << dp[N][K] << '\n';

	// Method 2: Using prefix sum
	for ( int i = 1; i <= N; i++ ) {
		dp[i][1] = dp[i - 1][1] + 1;
		for ( int j = 2; j <= K; j++ )
			dp[i][j] = ( dp[i - 1][j] + dp[i][j - 1] ) % MOD;
	}

	cout << (dp[N][K] - dp[N - 1][K] + MOD) % MOD << '\n';

	// Method 3: Using value caculated already
	for ( int i = 1; i <= N; i++ ) {
		dp[i][1] = 1;
		for ( int j = 2; j <= K; j++ )
			dp[i][j] = ( dp[i - 1][j] + dp[i][j - 1] ) % MOD;
	}

	cout << dp[N][K] << '\n';

	return 0;
}
