// Baekjoon01495_Guitarist.cpp
// https://www.acmicpc.net/problem/1495
#include <iostream>

#define NOTFILL -2

using namespace std;

int n, s, limit;
int volumes[101], dp[100][1'001];

int playGuitar( int idx, int currVolume );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s >> limit;

	for ( int i = 0; i < n; i++ )
		cin >> volumes[i];

	for ( int i = 0; i < n + 1; i++ )
		fill( dp[i], dp[i] + limit + 1, NOTFILL );

	cout << playGuitar( 0, s ) << '\n';

	return 0;
}

int playGuitar( int idx, int currVolume ) {
	if ( currVolume < 0 || currVolume > limit )
		return -1;
	else {
		if ( dp[idx][currVolume] == NOTFILL  ) {
			if ( idx == n )
				dp[idx][currVolume] = currVolume;
			else {
				int up = playGuitar( idx + 1, currVolume + volumes[idx] );
				int down = playGuitar( idx + 1, currVolume - volumes[idx] );

				if ( up == -1 && down == -1 )
					dp[idx][currVolume] = -1;
				else
					dp[idx][currVolume] = max( up, down );
			}
		}

		return dp[idx][currVolume];
	}
}
