// Baekjoon14938_SogangGround.cpp
// https://www.acmicpc.net/problem/14938

/*
Review
 * Date
 01/06/2021

 * Solution
 기본적인 Floyd-Warshall 문제이다.
 모든 최단 경로 쌍을 구한 뒤에 모든 최단 경로를 탐색하며 limit보다 작은 거리에 있는 Item의 갯수들을 더한다.

 * Idea
 시작점이 정해져있지 않다는 것을 깨닫고 모든 최단 경로 쌍을 구해야한다는 것을 알았다. -> Floyd-Warshall
*/

#include <iostream>
#include <algorithm> /* fill() */

#define INF 1'000'000'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, limit, e;
	cin >> n >> limit >> e;

	int item[101];
	for ( int i = 1; i <= n; i++ )
		cin >> item[i];

	int dist[101][101];
	for ( int i = 1; i <= n; i++ ) {
		fill( dist[i], dist[i] + n + 1, INF );
		dist[i][i] = 0;
	}

	for ( int i = 0; i < e; i++ ) {
		int a, b, l;
		cin >> a >> b >> l;

		dist[a][b] = min( dist[a][b], l );
		dist[b][a] = min( dist[b][a], l );
	}

	for ( int k = 1; k <= n; k++ )
		for ( int i = 1; i <= n; i++ )
			for ( int j = 1; j <= n; j++ )
				dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );

	int ans = 0;
	for ( int i = 1; i <= n; i++ ) {
		int sum = 0;
		for ( int j = 1; j <= n; j++ )
			if ( dist[i][j] <= limit )
				sum += item[j];

		ans = max( ans, sum );
	}

	cout << ans << '\n';

	return 0;
}
