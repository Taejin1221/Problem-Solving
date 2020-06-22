// Baekjoon11726_2xnTiling.cpp
// https://www.acmicpc.net/problem/11726
#include <iostream>

using namespace std;

int main(void) {
	int dp[1001] = { 0, 1, 2 };

	int n;
	cin >> n;
	for ( int i = 3; i <= n; i++ )
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[n] << '\n';

	return 0;
}