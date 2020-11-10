// Baekjoon01325_EffectiveHacking.cpp
// https://www.acmicpc.net/problem/1325
#include <iostream>
#include <vector>
#include <algorithm> /* fill */

#define LINEFEED '\n'
#define MAX 10'001

using namespace std;

int cnt;
bool visited[MAX];
vector<int> adjList[MAX];

void dfs( int curr ) {
	cnt++;
	for ( int& next : adjList[curr] ) {
		if ( !visited[next] ) {
			visited[next] = true;
			dfs( next );
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		adjList[b].push_back( a );
	}

	int maxConnection = 0, hack[MAX];
	for ( int i = 1; i <= n; i++ ) {
		fill( visited, visited + n + 1, false );
		cnt = 0;

		visited[i] = true;
		dfs( i );
		hack[i] = cnt;
		maxConnection = max( maxConnection, hack[i] );
	}

	for ( int i = 1; i <= n; i++ )
		if ( hack[i] == maxConnection )
			cout << i << ' ';
	cout << LINEFEED;

	return 0;
}
