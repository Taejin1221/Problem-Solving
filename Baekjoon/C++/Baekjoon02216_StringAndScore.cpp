// Baekjoon02216_StringAndScore.cpp
// https://www.acmicpc.net/problem/2216
#include <iostream>
#include <algorithm>
#include <string>

#define INF -1'000'000'000

using namespace std;

int max( int a, int b, int c ) {
	return ( max( a, max( b, c ) ) );
}

int A, B, C;
int n, m;
string str1, str2;
int dp[3000][3000];

int GetScore( int aIdx, int bIdx ) {
	if ( aIdx == n && bIdx == m )
		return 0;
	else if ( aIdx == n )
		return B * (m - bIdx);
	else if ( bIdx == m )
		return B * (n - aIdx);
	else {
		if ( dp[aIdx][bIdx] == INF ) {
			int a = GetScore( aIdx + 1, bIdx + 1 ) + (( str1[aIdx] == str2[bIdx] ) ? A : C);
			int b = GetScore( aIdx + 1, bIdx ) + B;
			int c = GetScore( aIdx, bIdx + 1 ) + B;

			dp[aIdx][bIdx] = max( a, b, c );
		}

		return dp[aIdx][bIdx];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;
	cin >> str1;
	cin >> str2;

	n = str1.size(), m = str2.size();
	for ( int i = 0; i < n; i++ )
		fill( dp[i], dp[i] + m, INF );

	cout << GetScore( 0, 0 ) << '\n';

	return 0;
}
