// Baekjoon01516_GameDevelopment.cpp
// https://www.acmicpc.net/problem/1516
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int costTime[501], indegree[501] = { 0, };

	vector<int> adjList[501];
	for ( int i = 1; i <= n; i++ ) {
		cin >> costTime[i];

		int u;
		cin >> u;
		while ( u != -1 ) {
			indegree[i]++;
			adjList[u].push_back( i );

			cin >> u;
		}
	}

	queue<int> q;
	for ( int i = 1; i <= n; i++ )
		if ( !indegree[i] )
			q.push( i );

	int startTime[501] = { 0, }, endTime[501] = { 0, };
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();
		endTime[curr] = startTime[curr] + costTime[curr];

		for ( const int& adj : adjList[curr] ) {
			startTime[adj] = max( startTime[adj], endTime[curr] );
			if ( --indegree[adj] == 0 )
				q.push( adj );
		}
	}

	for ( int i = 1; i <= n; i++ )
		cout << endTime[i] << '\n';

	return 0;
}