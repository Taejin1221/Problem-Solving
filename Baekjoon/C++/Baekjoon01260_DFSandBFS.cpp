// Baekjoon01260_DFSandBFS.cpp
// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <algorithm> /* sort() */
#include <vector>
#include <queue>

#define MAX_ARR_SIZE 1001
#define VISIT true

#define forloop( from, to ) for( int i = from; i < to; i++ )

using namespace std;

vector<int> graph[MAX_ARR_SIZE];
bool visited_dfs[MAX_ARR_SIZE] = { false, };
bool visited_bfs[MAX_ARR_SIZE] = { false, };

void dfs( int curr );
void bfs( int curr );

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	forloop( 0, m ) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back( b );
		graph[b].push_back( a );
	}

	forloop( 1, (n + 1) )
		sort( graph[i].begin(), graph[i].end() );

	dfs( v ); cout << '\n';
	bfs( v ); cout << '\n';

	return 0;
}

void dfs( int curr ) {
	cout << curr << ' ';
	visited_dfs[curr] = VISIT;	
	forloop( 0, graph[curr].size() ) {
		int adjVertex = graph[curr][i];
		if ( !visited_dfs[adjVertex] )
			dfs( adjVertex );
	}
}

void bfs( int curr ) {
	queue<int> q;

	q.push( curr );
	visited_bfs[curr] = VISIT;
	while ( !q.empty() ) {
		int adjVertex = q.front(); q.pop();
		cout << adjVertex << ' ';

		for ( int i = 0; i < graph[adjVertex].size(); i++ ) {
			int next = graph[adjVertex][i];
			if ( !visited_bfs[next] ) {
				visited_bfs[next] = VISIT;
				q.push( next );
			}
		}
	}
}