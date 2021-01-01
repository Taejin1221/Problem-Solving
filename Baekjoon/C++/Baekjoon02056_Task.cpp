// Baekjoon02056_Task.cpp
// https://www.acmicpc.net/problem/2056
#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 10'001	

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;	

	int indegree[MAX_SIZE] = { 0, };
	int taskTime[MAX_SIZE];

	queue<int> q;
	vector<int> adjList[MAX_SIZE];
	for ( int i = 1; i <= n; i++ ) {
		cin >> taskTime[i];

		int t;
		cin >> t;
		while ( t-- ) {
			int v; cin >> v;

			indegree[i]++;
			adjList[v].push_back( i );
		}

		if ( indegree[i] == 0 )
			q.push( i );
	}

	int ans = 0;
	int startTime[MAX_SIZE] = { 0, }, endTime[MAX_SIZE];
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();
		endTime[curr] = startTime[curr] + taskTime[curr];

		for ( int& adjV : adjList[curr] ) {
			if ( --indegree[adjV] == 0 )
				q.push( adjV );

			startTime[adjV] = max( startTime[adjV], endTime[curr] );
		}

		ans = max( ans, endTime[curr] );
	}

	cout << ans << '\n';

	return 0;
}