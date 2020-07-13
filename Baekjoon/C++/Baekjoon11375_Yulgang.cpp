// Baekjoon11375_Yulgang.cpp
// https://www.acmicpc.net/problem/11375
#include <iostream>
#include <algorithm> /* fill() */
#include <vector>

#define endl '\n'
#define MAX_ARR_SIZE 1'000

using namespace std;

int path[MAX_ARR_SIZE];
bool visited[MAX_ARR_SIZE];
vector<int> jobList[MAX_ARR_SIZE];

bool dfs( int people );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	fill ( path, path + m, -1 );
	for ( int i = 0; i < n; i++ ) {
		int jobs; cin >> jobs;

		while ( jobs-- ) {
			int job; cin >> job;
			jobList[i].push_back( job - 1 );
		}
	}

	int maxJob = 0;
	for ( int i = 0; i < n; i++ ) {
		fill( visited, visited + m, false );
		if ( dfs( i ) )
			maxJob++;
	}

	cout << maxJob << endl;

	return 0;
}

bool dfs( int people ) {
	for ( int i = 0; i < jobList[people].size(); i++ ) {
		int job = jobList[people][i];

		if ( visited[job] )
			continue;

		visited[job] = true;
		if ( path[job] == -1 || dfs( path[job] ) ) {
			path[job] = people;
			return true;
		}
	}

	return false;
}
