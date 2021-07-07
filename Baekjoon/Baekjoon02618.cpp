// Baekjoon02618_PoliceCar.cpp
// https://www.acmicpc.net/problem/2618
#include <iostream>
#include <cstring>

#define ABS(x) (( (x) > 0 ) ? ( x ) : -( x ))

using namespace std;

struct Position {
	int r, c;
};

int n, w;
int dp[1002][1002];
int cars[1002][1002];
Position arr[1002];

int distance( Position a, Position b ) {
	return ( ABS( a.r - b.r ) + ABS( a.c - b.c ) );
}

int minPath( int a, int b ) {
	int here = max( a, b ) + 1;
	if ( here == w + 2 )
		return 0;

	if ( dp[a][b] == -1 ) {
		int min1 = minPath( here, b ) + distance( arr[a], arr[here] );
		int min2 = minPath( a, here ) + distance( arr[b], arr[here] );

		if ( min1 < min2 ) {
			dp[a][b] = min1;
			cars[a][b] = 1;
		} else {
			dp[a][b] = min2;
			cars[a][b] = 2;
		}
	}

	return dp[a][b];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w;

	arr[0].r = arr[0].c = 1;
	arr[1].r = arr[1].c = n;

	memset( dp, -1, sizeof( dp ) );
	for ( int i = 2; i < w + 2; i++ )
		cin >> arr[i].r >> arr[i].c;

	cout << minPath( 0, 1 ) << '\n';

	int car1 = 0, car2 = 1;
	while ( max( car1, car2 ) + 1 < w + 2 ) {
		cout << cars[car1][car2] << '\n';

		if ( cars[car1][car2] == 2 )
			car2 = max( car1, car2 ) + 1;
		else
			car1 = max( car1, car2 ) + 1;
	}

	return 0;
}