// Baekjoon01865_Wormhole.cpp
// https://acmicpc.net/problem/1865
#include <iostream>

#define INF 2'000'000'000

using namespace std;

struct Edge {
	int u, v, time;
	Edge( ): u(0), v(0), time(0) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n, m, w;
		cin >> n >> m >> w;

		int shortest[500] = { 0, };
		for ( int i = 1; i < n; i++ )
			shortest[i] = INF;

		Edge edges[5000], wormholes[200];
		for ( int i = 0; i < 2 * m; i += 2 ) {
			int s, e, t;
			cin >> s >> e >> t;

			edges[i].u = s - 1;
			edges[i].v = e - 1;
			edges[i].time = t;

			edges[i + 1].u = e - 1;
			edges[i + 1].v = s - 1;
			edges[i + 1].time = t;
		}

		for ( int i = 0; i < w; i++ ) {
			int s, e, t;
			cin >> s >> e >> t;

			wormholes[i].u = s - 1;
			wormholes[i].v = e - 1;
			wormholes[i].time = -t;
		}

		bool isCycle = false;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < 2 * m; j++ ) {
				int s = edges[j].u, e = edges[j].v, t = edges[j].time;
				if ( shortest[e] > shortest[s] + t ) {
					shortest[e] = shortest[s] + t;
					if ( i == n - 1 )
						isCycle = true;
				}
			}

			for ( int j = 0; j < w; j++ ) {
				int s = wormholes[j].u, e = wormholes[j].v, t = wormholes[j].time;
				if ( shortest[e] > shortest[s] + t ) {
					shortest[e] = shortest[s] + t;
					if ( i == n - 1 )
						isCycle = true;
				}
			}
		}

		if ( isCycle )
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}
