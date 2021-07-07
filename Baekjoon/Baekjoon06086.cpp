// Baekjoon06086_MaxFlow.cpp
// https://www.acmicpc.net/problem/6086
#include <iostream>
#include <queue>
#include <vector>
#include <climits> /* INT_MAX */
#include <algorithm> /* fill() */

#define endl '\n'
#define INF INT_MAX
#define MAX_ARR_SIZE 128

using namespace std;

vector<char> adjList[MAX_ARR_SIZE];
int capacity[MAX_ARR_SIZE][MAX_ARR_SIZE];

int GetMaximumFlow( char start, char end );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		char s, e; int c;
		cin >> s >> e >> c;

		adjList[s].push_back( e );
		adjList[e].push_back( s );
		capacity[s][e] += c;
		capacity[e][s] += c;
	}

	cout << GetMaximumFlow( 'A', 'Z' ) << endl;

	return 0;
}

int GetMaximumFlow( char start, char end ) {
	int result = 0;
	char path[MAX_ARR_SIZE];
	int flowed[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0, };
	while ( true ) {
		queue<char> q;
		q.push( start );

		fill( path, path + MAX_ARR_SIZE, -1 );
		while ( !q.empty() && path[end] == -1 ) {
			char curr = q.front(); q.pop();

			for ( char adj : adjList[curr] ) {
				if ( capacity[curr][adj] - flowed[curr][adj] > 0 && path[adj] == -1 ) {
					q.push( adj );
					path[adj] = curr;
					if ( adj == end )
						break;
				}
			}
		}

		if ( path[end] == -1 )
			break;

		int flow = INF;
		for ( char i = end; i != start; i = path[i] )
			flow = min( flow, capacity[path[i]][i] - flowed[path[i]][i] );

		for ( char i = end; i != start; i = path[i] ) {
			flowed[path[i]][i] += flow;
			flowed[i][path[i]] -= flow;
		}

		result += flow;
	}

	return result;
}