// Baekjoon02294_Coin2.cpp
// https://www.acmicpc.net/problem/2294
#include <iostream>
#include <algorithm>

#define INF 10'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int coin[100];
	for ( int i = 0; i < n; i++ )
		cin >> coin[i];

	int dp[10'001];
	fill( dp, dp + 10'001, INF );

	dp[0] = 0;
	for ( int i = 1; i <= k; i++ )
		for ( int j = 0; j < n; j++ )
			if ( i >= coin[j] )
				dp[i] = min( dp[i], dp[i - coin[j]] + 1 );

	if ( dp[k] != INF )
		cout << dp[k];
	else
		cout << -1;
	cout << endl;

	return 0;
}
