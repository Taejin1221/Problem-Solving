// Baekjoon01005_ACMCraft.cpp
// https://www.acmicpc.net/problem/1005
#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 1'001

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n, k;
		cin >> n >> k;

		int costTime[MAX_SIZE];
		for ( int i = 1; i <= n; i++ )
			cin >> costTime[i];

		vector<int> adjList[MAX_SIZE];
		int indegree[MAX_SIZE] = { 0, };
		for ( int i = 0; i < k; i++ ) {
			int u, v;
			cin >> u >> v;

			adjList[u].push_back( v );
			indegree[v]++;
		}

		int target;
		cin >> target;

		queue<int> q;
		for ( int i = 1; i <= n; i++ )
			if ( indegree[i] == 0 )
				q.push( i );

		int startTime[MAX_SIZE] = { 0, }, endTime[MAX_SIZE];
		while ( !q.empty() ) {
			int curr = q.front(); q.pop();
			endTime[curr] = startTime[curr] + costTime[curr];

			if ( curr == target )
				break;

			for ( int& adjV : adjList[curr] ) {
				if ( --indegree[adjV] == 0 )
					q.push( adjV );

				startTime[adjV] = max( startTime[adjV], endTime[curr] );
			}
		}

		cout << endTime[target] << '\n';
	}

	return 0;
}
