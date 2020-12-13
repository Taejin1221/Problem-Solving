// Baekjoon15486_Quit2.cpp
// https://www.acmicpc.net/problem/15486
#include <iostream>

#define MAX_SIZE 1'500'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int time[MAX_SIZE], profit[MAX_SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> time[i] >> profit[i];

	int dp[MAX_SIZE] = { 0, };
	dp[time[0]] = profit[0];

	for ( int i = 1; i < n; i++ ) {
		dp[i] = max( dp[i], dp[i - 1] );

		int nextTime = i + time[i];
		if ( nextTime <= n )
			dp[nextTime] = max( dp[nextTime], dp[i] + profit[i] );
	}

	dp[n] = max( dp[n], dp[n - 1] );

	cout << dp[n] << '\n';

	return 0;
}
