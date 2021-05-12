// Baekjoon02602_LordOfRings.cpp
// https://www.acmicpc.net/problem/2602
#include <iostream>

using namespace std;

int scrollSize, strSize;
string scroll, str[2];

int dp[2][100][20];

int func( int isEvil, int startIdx, int scrollIdx ) {
	if ( scrollIdx < scrollSize) {
		if ( dp[isEvil][startIdx][scrollIdx] == -1 ) {
			int ans = 0;
			for ( int i = startIdx; i < strSize; i++ )
				if ( scroll[scrollIdx] == str[isEvil][i] )
					ans += func( !isEvil, i + 1, scrollIdx + 1 );

			dp[isEvil][startIdx][scrollIdx] = ans;
		}

		return dp[isEvil][startIdx][scrollIdx];
	} else {
		return 1;
	}
}

int main(void) {
	cin >> scroll;
	cin >> str[0];
	cin >> str[1];

	scrollSize = scroll.size();
	strSize = str[0].size();

	for ( int i = 0; i < 2; i++ )
		for ( int j = 0; j < strSize; j++ )
			for ( int k = 0; k < scrollSize; k++ )
				dp[i][j][k] = -1;

	int ans = func( 0, 0, 0 ) + func( 1, 0, 0 );
	cout << ans << '\n';

	return 0;
}