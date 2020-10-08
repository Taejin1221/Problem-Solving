// Programmers_DFS-BFS_Network.cpp
// https://programmers.co.kr/learn/courses/30/lessons/43162
#include <vector>

using namespace std;

void dfs( vector<vector<int>>& computers, vector<bool>& visited, int curr ) {
	for ( int i = 0; i < computers.size(); i++ ) {
		if ( computers[curr][i] && !visited[i] ) {
			visited[i] = true;
			dfs( computers, visited, i );
		}
	}
}

int solution( int n, vector<vector<int>> computers ) {
	int ans = 0;
	vector<bool> visited ( computers.size() );

	for ( int i = 0; i < computers.size(); i++ ) {
		if ( !visited[i] ) {
			dfs( computers, visited, i );
			ans++;
		}
	}

	return ans;
}