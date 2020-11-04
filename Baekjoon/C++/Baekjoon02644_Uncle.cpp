// Baekjoon02644_Uncle.cpp
// https://www.acmicpc.net/problem/2644
#include <iostream>
#include <vector>

using namespace std;

int ans = -1, start, target;
bool visited[101];
vector<int> adjList[101];

void dfs( int curr, int chon ) {
	if ( curr == target )
		ans = chon;

	for ( int& next : adjList[curr] ) {
		if ( !visited[next] ) {
			visited[next] = true;
			dfs( next, chon + 1 );
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cin >> start >> target;

	int m;
	cin >> m;

	for ( int i = 0; i < m; i++ ) {
		int x, y;
		cin >> x >> y;

		adjList[x].push_back( y );
		adjList[y].push_back( x );
	}

	dfs( start, 0 );

	cout << ans << '\n';

	return 0;
}
