// Baekjoon09466_TermProject.cpp
// https://www.acmicpc.net/problem/9466
#include <iostream>
#include <cstring>

#define MAX_ARR_SIZE 100001

using namespace std;

int n;
int wants[MAX_ARR_SIZE];
int stck[MAX_ARR_SIZE];
bool cycle[MAX_ARR_SIZE];
bool visited[MAX_ARR_SIZE];


void dfs( int start ) {
	int stckIdx = 0;
	stck[stckIdx++] = start;

	visited[start] = true;
	int next = wants[start];
	while ( !visited[next] ) {
		stck[stckIdx++] = next;
		visited[next] = true;
		next = wants[next];
	}

	bool find = false;
	for ( int i = 0; i < stckIdx; i++ ) {
		if ( stck[i] == next )
			find = true;
		cycle[stck[i]] = find;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int count = 0;

		cin >> n;
		for ( int i = 1; i <= n; i++ )
			cin >> wants[i];

		memset( cycle, false, n + 1 );
		memset( visited, false, n + 1 );
		for ( int i = 1; i <= n; i++ )
			if ( !visited[i] )
				dfs( i );

		for ( int i = 1; i <= n; i++ )
			if ( !cycle[i] )
				count++;

		cout << count << '\n';
	}

	return 0;
}
