// Baekjoon02410_SumOfExponent2.cpp
// https://www.acmicpc.net/problem/2410
#include <iostream>

#define SIZE 1'000'001
#define MOD 1'000'000'000

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int exponent[21];
	for ( int i = 0; i <= 20; i++ )
		exponent[i] = (1 << i);

	int dp[SIZE][21] = { 0, };
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j <= 20; j++ ) {
			if ( exponent[j] < i ) {
				long long result = 0ll;
				for ( int k = 0; k <= j; k++ )
					result = ( result + dp[i - exponent[j]][k] ) % MOD;
				dp[i][j] = result;
			} else if ( exponent[j] == i )
				dp[i][j] = 1;

			dp[i][j] %= MOD;
		}
	}

	long long ans = 0ll;
	for ( int i = 0; i <= 20; i++ )
		ans = (ans + dp[n][i]) % MOD;

	cout << ans << '\n';

	return 0;
}