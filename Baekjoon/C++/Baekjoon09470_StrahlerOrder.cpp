// Baekjoon09470_StrahlerOrder.cpp
// https://www.acmicpc.net/problem/9470
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int k, n, p;
		cin >> k >> n >> p;

		int indegree[1'001] = { 0, };
		vector<int> adjList[1'001];
		for ( int i = 0; i < p; i++ ) {
			int a, b;
			cin >> a >> b;

			adjList[a].push_back( b );
			indegree[b]++;
		}

		int strahler[1'001] = { 0, }, tempStrahler[1'001] = { 0, };

		queue<int> q;
		for ( int i = 1; i <= n; i++ ) {
			if ( !indegree[i] ) {
				q.push( i );
				strahler[i] = 1;
			}
		}

		while ( !q.empty() ) {
			int currNode = q.front(); q.pop();
			strahler[currNode] = max( strahler[currNode], tempStrahler[currNode] );

			for ( int& adjNode : adjList[currNode] ) {
				if ( !(--indegree[adjNode]) )
					q.push( adjNode );

				if ( tempStrahler[adjNode] < strahler[currNode] )
					tempStrahler[adjNode] = strahler[currNode];
				else {
					strahler[adjNode] = tempStrahler[adjNode] + 1;
				}
			}
		}

		cout << k << ' ' << strahler[n] << '\n';
	}

	return 0;
}