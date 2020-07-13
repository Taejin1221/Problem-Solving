// Baekjoon11376_Yulgang2.cpp
// https://www.acmicpc.net/problem/11376
#include <iostream>
#include <algorithm> /* fill() */
#include <vector>

#define endl '\n'
#define MAX_ARR_SIZE 2'000

using namespace std;

int path[MAX_ARR_SIZE];
bool visited[MAX_ARR_SIZE];
vector<int> adjList[MAX_ARR_SIZE];

bool dfs( int curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	fill( path, path + m * 2, -1 );
	for ( int i = 0; i < n * 2; i += 2 ) {
		int jobNum;
		cin >> jobNum;

		while ( jobNum-- ) {
			int job;
			cin >> job;

			adjList[i].push_back( job - 1 );
			adjList[i + 1].push_back( job - 1 );
		}
	}

	int maxJob = 0;
	for ( int i = 0; i < n * 2; i++ ) {
		fill( visited, visited + m * 2, false );
		if ( dfs( i ) )
			maxJob++;
	}

	cout << maxJob << endl;

	return 0;
}

bool dfs( int curr ) {
	for ( int i = 0; i < adjList[curr].size(); i++ ) {
		int adj = adjList[curr][i];

		if ( !visited[adj] ) {
			visited[adj] = true;
			if ( path[adj] == -1 || dfs( path[adj] ) ) {
				path[adj] = curr;
				return true;
			}
		}
	}

	return false;
}