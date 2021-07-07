// Baekjoon14863_FromSeoulToGyeongsan.cpp
// https://www.acmicpc.net/problem/14863
// KOI 2017 초등부 3
#include <iostream>
#include <algorithm>

#define MAX_TIME 100'001

using namespace std;

struct Segment {
	int time, charity;
	Segment( int t, int c ): time(t), charity(c) { }
	Segment( ): time(0), charity(0) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	// row -> 구간 번호, col -> 시간, dp[r][c] -> 모금액
	int dp[101][MAX_TIME] = { 0, };
	Segment walk, bike;
	cin >> walk.time >> walk.charity;
	cin >> bike.time >> bike.charity;

	dp[1][walk.time] = walk.charity;
	dp[1][bike.time] = max( dp[1][bike.time], bike.charity);

	for ( int i = 1; i < N; i++ ) {
		Segment walk, bike;
		cin >> walk.time >> walk.charity;
		cin >> bike.time >> bike.charity;

		for ( int j = 1; j <= K; j++ ) {
			if ( dp[i][j] != 0 ) {
				if ( j + walk.time <= K )
					dp[i + 1][j + walk.time] = max( dp[i + 1][j + walk.time], dp[i][j] + walk.charity );

				if ( j + bike.time <= K )
					dp[i + 1][j + bike.time] = max( dp[i + 1][j + bike.time], dp[i][j] + bike.charity );
			}
		}
	}

	int ans = 0;
	for ( int i = 1; i <= K; i++ )
		ans = max( ans, dp[N][i] );

	cout << ans << '\n';

	return 0;
}
