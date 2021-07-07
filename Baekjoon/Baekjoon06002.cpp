// Baekjoon06002_JobHunt.cpp
// https://www.acmicpc.net/problem/6002
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
	int v, u, w;
	Edge( ): v(0), u(0), w(0) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dollar, path, city, flight, start;
	cin >> dollar >> path >> city >> flight >> start;

	Edge edges[500];
	for ( int i = 0; i < path; i++ ) {
		cin >> edges[i].v >> edges[i].u;
		edges[i].w = -dollar;
	}

	int edgeSize = path + flight;
	for ( int i = path; i < edgeSize; i++ ) {
		cin >> edges[i].v >> edges[i].u >> edges[i].w;
		edges[i].w -= dollar;
	}


	long shortestPath[221];
	fill( shortestPath, shortestPath + city + 1, LONG_MAX );

	shortestPath[start] = -dollar;
	for ( int i = 0; i < city - 1; i++ ) {
		for ( int j = 0; j < edgeSize; j++ ) {
			int v = edges[j].v, u = edges[j].u, w = edges[j].w;
			if ( shortestPath[v] != LONG_MAX && shortestPath[u] > shortestPath[v] + w )
				shortestPath[u] = shortestPath[v] + w;
		}
	}

	bool isCycle = false;
	for ( int j = 0; j < edgeSize; j++ ) {
		int v = edges[j].v, u = edges[j].u, w = edges[j].w;
		if ( shortestPath[v] != LONG_MAX && shortestPath[u] > shortestPath[v] + w )
			isCycle = true;
	}

	if ( isCycle )
		cout << -1 << '\n';
	else {
		long ans = LONG_MAX;
		for ( int i = 1; i <= city; i++ )
			ans = min( ans, shortestPath[i] );
		cout << -ans << '\n';
	}

	return 0;
}
