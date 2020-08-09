// Baekjoon01389_KevinBacon6DegreesOfSeparation.cpp
// https://www.acmicpc.net/problem/1389
#include <iostream>
#include <climits>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	bool adjMat[101][101] = { false, };
	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		adjMat[a][b] = true;
		adjMat[b][a] = true;
	}

	int bacon[101] = { INT_MAX, };
	for ( int i = 1; i <= n; i++ ) {
		bool visited[101] = { false, };

		queue<pii> q;
		q.push( { i, 0 } ); visited[i] = true;
		while ( !q.empty() ) {
			pii curr = q.front(); q.pop();
			bacon[i] += curr.second;

			for ( int j = 1; j <= n; j++ ) {
				if ( adjMat[curr.first][j] && !visited[j] ) {
					visited[j] = true;
					q.push( { j, curr.second + 1 } );
				}
			}
		}
	}

	int minNode = 0;
	for ( int i = 1; i <= n; i++ )
		if ( bacon[i] < bacon[minNode] )
			minNode = i;

	cout << minNode << '\n';

	return 0;
}