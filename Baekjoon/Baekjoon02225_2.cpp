#include <iostream>
#include <algorithm>

#define MOD 1'000'000'000

using namespace std;

int dp[201][201];

// Solution 1: Recursion without Memoization
int Decom( int N, int K ) {
	if ( N == 0 || K == 1 )
		return 1;
	else if ( K == 0 )
		return 0;
	else {
		int sum = 0;
		for ( int i = 0; i <= N; i++ )
			sum = (sum + Decom( i, K - 1 )) % MOD;

		return sum;
	}
}

// Solution 2: Recursion with Memoization
int Decom( int N, int K ) {
	if ( dp[N][K] == -1 ) {
		if ( N == 0 || K == 1 )
			dp[N][K] = 1;
		else if ( K == 0 )
			dp[N][K] = 0;
		else {
			int sum = 0;
			for ( int i = 0; i <= N; i++ )
				sum = (sum + Decom( i, K - 1 )) % MOD;

			dp[N][K] = sum;
		}
	}

	return dp[N][K];
}

// Solution 3: Recursion O(NK)
int Decom( int N, int K ) {
	if ( dp[N][K] == -1 ) {
		if ( N == 0 || K == 1 )
			dp[N][K] = 1;
		else if ( K == 0 )
			dp[N][K] = 0;
		else {
			int sum = 0;
			sum = (Decom( i, K - 1 ) + Decom( i - 1, K )) % MOD;

			dp[N][K] = sum;
		}
	}

	return dp[N][K];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for ( int i = 0; i < 201; i++ )
		fill( dp[i], dp[i] + 201, -1 );

	int N, K;
	cin >> N >> K;

	cout << Decom( N, K ) << '\n';

	return 0;
}