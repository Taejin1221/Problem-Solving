// Baekjoon02305_PlacingSeat.cpp
// https://www.acmicpc.net/problem/2305
// Reference : https://kimcodingvv.github.io/BOJ-2305/
#include <iostream>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	int fib[41], fibSum[41];
	fib[0] = fib[1] = 1;
	fibSum[0] = 1; fibSum[1] = 2;

	for ( int n = 2; n <= N; n++ ) {
		fib[n] = fib[n - 1] + fib[n - 2];
		fibSum[n] = fibSum[n - 1] + fib[n];
	}

	int dp[41];
	dp[1] = 1; dp[2] = 2;
	for ( int n = 3; n <= N; n++ )
		dp[n] = dp[n - 1] + dp[n - 2] + fibSum[n - 2] + fibSum[n - 3];

	cout << dp[K] * fib[N - K] + dp[N - K + 1] * fib[K - 1] - fib[N - K] * fib[K - 1] << '\n';

	return 0;
}