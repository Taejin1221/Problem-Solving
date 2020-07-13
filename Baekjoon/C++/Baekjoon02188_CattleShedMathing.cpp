// Baekjoon02188_CattleShedMathing.cpp
// https://www.acmicpc.net/problem/2188
#include <iostream>
#include <algorithm> /* fill() */
#include <vector>

#define endl '\n'
#define MAX_ARR_SIZE 201

using namespace std;

int cow[MAX_ARR_SIZE];
bool visited[MAX_ARR_SIZE];
vector<int> adjList[MAX_ARR_SIZE];

bool dfs( int curr );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ ) {
		int sheds; cin >> sheds;

		while ( sheds-- ) {
			int shed; cin >> shed;
			adjList[i].push_back( shed );
		}
	}

	int maxCow = 0;
	for ( int i = 1; i <= n; i++ ) {
		fill( visited, visited + m + 1, false );
		if ( dfs( i ) )
			maxCow++;
	}

	cout << maxCow << endl;

	return 0;
}

bool dfs( int curr ) {
	for ( int i = 0; i < adjList[curr].size(); i++ ) {
		int adj = adjList[curr][i];

		if ( !visited[adj] ){
			visited[adj] = true;
			if ( !cow[adj] || dfs( cow[adj] ) ) {
				cow[adj] = curr;
				return true;
			}
		}
	}

	return false;
}