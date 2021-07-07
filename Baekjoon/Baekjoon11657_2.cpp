// Baekjoon11657_Timemachine(2).cpp
// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
	int v, u, w;
	Edge( ): v(0), u(0), w(0) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	Edge edges[6'000];
	for ( int i = 0; i < m; i++ )
		cin >> edges[i].v >> edges[i].u >> edges[i].w;

	long shortestPath[501] = { 0, };
	fill( shortestPath + 2, shortestPath + n + 1, LONG_MAX );

	bool isCycle = false;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			int v = edges[j].v, u = edges[j].u, w =edges[j].w;
			if ( (shortestPath[v] != LONG_MAX) && (shortestPath[u] > shortestPath[v] + w) ) {
				if ( i == n - 1 )
					isCycle = true;
				shortestPath[u] = shortestPath[v] + w;
			}
		}
	}

	if ( isCycle )
		cout << -1 << '\n';
	else {
		for ( int i = 2; i <= n; i++ ) {
			if ( shortestPath[i] != LONG_MAX )
				cout << shortestPath[i];
			else
				cout << -1;
			cout << '\n';
		}
	}

	return 0;
}
