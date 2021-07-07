// Baekjoon01707_BipartiteGraph.cpp
// https://www.acmicpc.net/problem/1707
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

void solve( ) {
	int v, e;
	cin >> v >> e;

	vector<int> adjList[20'001];
	for ( int i = 0; i < e; i++ ) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back( b );
		adjList[b].push_back( a );
	}

	queue<int> q;
	int group[20'001] = { 0, }; // -1, 1: Group, 0 : No Group

	int visitNum = 0;
	bool isBipartite = true;
	while ( visitNum < v ) {
		for ( int i = 1; i <= v; i++ ) {
			if ( group[i] == 0 ) {
				group[i] = 1;
				visitNum++;

				q.push( i );
				break;
			}
		}

		while ( !q.empty() ) {
			int curr = q.front(); q.pop();
			for ( int& adj : adjList[curr] ) {
				if ( group[adj] == 0 ) {
					group[adj] = -group[curr];
					visitNum++;

					q.push( adj );
				} else {
					if ( group[curr] == group[adj] ) {
						isBipartite = false;
						break;
					}
				}
			}

			if ( !isBipartite )
				break;
		}

		if ( !isBipartite )
			break;
	}

	if ( isBipartite )
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solve();
	}

	return 0;
}