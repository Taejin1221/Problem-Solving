// Baekjoon11657_TimeMachine.cpp
// https://www.acmicpc.net/problem/11657
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Vertex {
	int v, w;
	Vertex( ) { }
	Vertex( int vertex, int weight ): v(vertex), w(weight) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Vertex> adjList[501];
	for ( int i = 0; i < m; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back( Vertex( b, c ) );
	}

	long shortest[501] = { 0, 0, };
	for ( int i = 2; i <= n; i++ )
		shortest[i] = LONG_MAX;

	bool isCycle = false;
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			for ( int k = 0; k < adjList[j].size(); k++ ) {
				int adjVertex = adjList[j][k].v, adjWeight = adjList[j][k].w;
				if ( shortest[j] != LONG_MAX && shortest[adjVertex] > shortest[j] + adjWeight ) {
					shortest[adjVertex] = shortest[j] + adjWeight;
					if ( i == n -1 )
						isCycle =  true;
				}	
			}
		}
	}

	if ( isCycle )
		cout << "-1\n";
	else
		for ( int i = 2; i <= n; i++ )
			cout << ( ( shortest[i] != LONG_MAX ) ? shortest[i] : -1) << '\n';

	return 0;
}