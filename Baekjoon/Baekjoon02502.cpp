// Baekjoon02502_TigerWantsToEatRicecake.cpp
// https://www.acmicpc.net/problem/2502
#include <iostream>

using namespace std;

int main(void) {
	int d, k;
	cin >> d >> k;

	int dp[2][31];
	dp[0][1] = 1; dp[0][2] = 0;
	dp[1][1] = 0; dp[1][2] = 1;

	for ( int i = 3; i <= d; i++ ) {
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}

	int a = dp[0][d], b = dp[1][d];
	for ( int i = 1; i <= k / a; i++ ) {
		int target = k - a * i;
		if ( target % b == 0 ) {
			cout << i << '\n' << target / b << '\n';
			break;
		}
	}

	return 0;
}