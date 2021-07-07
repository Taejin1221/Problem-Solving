// Baekjoon09658_StoneGame4.cpp
// https://www.acmicpc.net/problem/9658
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	// i개 남았을 때 돌을 가져가는 사람
	bool dp[1'001] = { false, false, true, false, true };
	for ( int i = 5; i <= n; i++ )
		dp[i] = !( dp[i - 1] && dp[i - 3] && dp[i - 4] );

	if ( dp[n] )
		cout << "SK";
	else
		cout << "CY";
	cout << '\n';

	return 0;
}