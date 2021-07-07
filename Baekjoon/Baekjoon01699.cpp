// Baekjoon01699_SumOfSquare.cpp
// https://www.acmicpc.net/problem/1699
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int dp[100'001] = { 0, 1, 2, };
	for ( int i = 3; i <= n; i++ ) {
		dp[i] = i;
		for ( int j = 1; j * j <= i; j++ )
			dp[i] = min( dp[i], dp[i - j * j] + 1 );
	}

	cout << dp[n] << '\n';

	return 0;
}