// Baekjoon02248_FindBinary.cpp
// https://www.acmicpc.net/problem/2248
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n, number1;
	long indexed;
	cin >> n >> number1 >> indexed;

	long dp[32][32];
	dp[1][0] = 1; dp[1][1] = 2;

	for ( int i = 2; i <= n; i++ ) {
		dp[i][0] = 1;
		for ( int j = 1; j < i; j++ )
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		dp[i][i] = dp[i -1][i - 1] * 2;
	}

	int binIdx = 0;
	char bin[33] = { 0, };
	for ( binIdx = 0; binIdx < n - 1; binIdx++ ) {
		int prev = n - binIdx - 1;
		if ( prev <= number1 )
			number1 = prev;

		if ( dp[prev][number1] >= indexed ) 
			bin[binIdx] = '0';
		else {
			bin[binIdx] = '1';
			indexed -= dp[prev][number1--];
		}
	}

	if ( indexed == 1 )
		bin[binIdx++] = '0';
	else
		bin[binIdx++] = '1';

	cout << bin << '\n';

	return 0;
}