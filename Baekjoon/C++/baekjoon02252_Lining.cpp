// Baekjoon02252_Lining.cpp
// https://www.acmicpc.net/problem/2252
#include <iostream>
#include <vector>

using namespace std;

int topolsIdx = 0;
int topols[32000];
bool visited[32001];
vector<int> adjList[32001];

void DFS( int start );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for ( int i = 1; i <= n; i++ )
		adjList[0].push_back( i );

	for ( int i = 0; i < m; i++ ) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back( b );
	}

	DFS( 0 );
	for ( int i = topolsIdx - 1; i >= 0; i-- )
		cout << topols[i] << ' ';
	cout << '\n';

	return 0;
}

void DFS( int start ) {
	visited[start] = true;
	for ( int i = 0; i < adjList[start].size(); i++ ) {
		if ( !visited[adjList[start][i]] ) {
			DFS( adjList[start][i] );
			topols[topolsIdx++] = adjList[start][i];
		}
	}
}
