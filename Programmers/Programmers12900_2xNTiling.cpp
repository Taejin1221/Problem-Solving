// Programmers12900_2xNTiling.cpp
// https://programmers.co.kr/learn/courses/30/lessons/12900
int solution( int n ) {
	int dp[60'001] = { 0, 1, 2, };
	for ( int i = 3; i <= n; i++ )
		dp[i] = ( dp[i - 1] + dp[i - 2] ) % 1'000'000'007;

	return dp[n];
}