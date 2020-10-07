// Programmers_DP_WayToSchool.cpp
// https://programmers.co.kr/learn/courses/30/lessons/42898
#include <vector>

#define MOD 1'000'000'007

using namespace std;

typedef long long ll;

int solution( int m, int n, vector<vector<int>> puddles ) {
	int answer = 0;

	int dp[101][101] = { 0, };
	for ( int i = 0; i < puddles.size(); i++ )
		dp[puddles[i][1]][puddles[i][0]] = -1;

	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= m; j++ ) {
			if ( i == 1 && j == 1 )
				dp[i][j] = 1;
			else if ( dp[i][j] != -1 ) {
				if ( dp[i][j - 1] != -1 )
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;

				if ( dp[i - 1][j] != -1 )
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
			}
		}
	}

	answer = dp[n][m];

	return answer;
}