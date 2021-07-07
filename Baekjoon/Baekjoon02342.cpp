// Baekjoon02342_DanceDanceRevolution.cpp
// https://www.acmicpc.net/problem/2342
#include <iostream>

#include <algorithm>

#define SIZE 100'001
#define INF 1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cost[5][5] = {
		{ 1, 2, 2, 2, 2 },
		{ 2, 1, 3, 4, 3 },
		{ 2, 3, 1, 3, 4 },
		{ 2, 4, 3, 1, 3 },
		{ 2, 3, 4, 3, 1 }
	};

	int dp[SIZE][5][5] = { 0, };
	for ( int i = 0; i < 5; i++ )
		fill( dp[0][i], dp[0][i] + 5, INF );

	dp[0][0][0] = 0;

	int direction, idx = 0;
	cin >> direction;
	while ( direction ) {
		idx++;
		for ( int i = 0; i < 5; i++ )
			fill( dp[idx][i], dp[idx][i] + 5, INF );

		for ( int i = 0; i < 5; i++ ) {
			for ( int j = 0; j < 5; j++ ) {
				int currCost = cost[j][direction];
				dp[idx][direction][i] = min( dp[idx][direction][i], dp[idx - 1][j][i] + currCost );
				dp[idx][i][direction] = min( dp[idx][i][direction], dp[idx - 1][i][j] + currCost );
			}
		}

		cin >> direction;
	}

	int ans = INF;
	for ( int i = 0; i < 5; i++ ) {
		for ( int j = 0; j < 5; j++ ) {
			ans = min( ans, dp[idx][j][i] );
			ans = min( ans, dp[idx][i][j] );
		}
	}

	cout << ans << '\n';

	return 0;
}