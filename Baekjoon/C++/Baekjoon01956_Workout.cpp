// Baekjoon01956_Workout.cpp
// https://www.acmicpc.net/problem/1956
#include <iostream>

#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;

	long adjMat[401][401];
	for ( int i = 1; i <= v; i++ )
		fill( adjMat[i], adjMat[i] + v + 1, INF );

	for ( int i = 0; i < e; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;

		adjMat[a][b] = c;
	}

	for ( int k = 1; k <= v; k++ )
		for ( int i = 1; i <= v; i++ )
			for ( int j = 1; j <= v; j++ )
				adjMat[i][j] = min( adjMat[i][j], adjMat[i][k] + adjMat[k][j] );

	int ans = INF;
	for ( int i = 1; i <= v; i++ )
		ans = min( ans, (int)adjMat[i][i] );

	if ( ans == INF )
		cout << -1;
	else
		cout << ans;
	cout << '\n';

	return 0;
}