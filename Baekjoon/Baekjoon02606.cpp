// Baekjoon02606_Virus.cpp
// https://www.acmicpc.net/problem/2606
#include <iostream>

#define VISIT true

using namespace std;

int virus, nodeNum, edgeNum;
bool visited[101];
bool networks[101][101];

void dfs( int curr );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);	

	cin >> nodeNum >> edgeNum;

	for ( int i = 0; i < edgeNum; i++ ) {
		int a, b;
		cin >> a >> b;

		networks[a][b] = true;
		networks[b][a] = true;
	}

	dfs( 1 );
	cout << virus << '\n';

	return 0;
}

void dfs( int curr ) {
	visited[curr] = VISIT;

	for ( int i = 1; i <= nodeNum; i++ ) {
		if ( networks[curr][i] ) {
			if ( !visited[i] ) {
				virus++;
				dfs( i );
			}
		}
	}
}
