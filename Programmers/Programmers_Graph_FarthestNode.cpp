// Programmers_Graph_FarthestNode.cpp
// https://programmers.co.kr/learn/courses/30/lessons/49189
#include <queue>

using namespace std;

int solution( int n, vector<vector<int>> edge ) {
	int ans = 0;

	vector<int> adjList[20'001];
	for ( int i = 0; i < edge.size(); i++ ) {
		adjList[edge[i][0]].push_back( edge[i][1] );
		adjList[edge[i][1]].push_back( edge[i][0] );
	}

	bool visited[20'001] = { false, };
	queue<int> q;
	int shortest[20'001] = { 0, };

	q.push( 1 );
	visited[1] = true;

	int maxPath = 0;
	while ( !q.empty() ) {
		int curr = q.front(); q.pop();

		for ( int& adj : adjList[curr] ) {
			if ( !visited[adj] ) {
				visited[adj] = true;
				shortest[adj] = shortest[curr] + 1;
				maxPath = max( maxPath, shortest[adj] );

				q.push( adj );
			}
		}
	}

	for ( int i = 1; i <= n; i++ )
		if ( shortest[i] == maxPath )
			ans++;

	return ans;
}