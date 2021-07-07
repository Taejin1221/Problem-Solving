// Baekjoon02667_GivingComplexNumber.cpp
// https://www.acmicpc.net/problem/2667
#include <cstdio>
#include <algorithm> /* sort() */
#include <vector>
#include <queue>

#define VISIT true

using namespace std;

int n;
char grid[25][25];
bool visited[25][25] = { false, };

int bfs( pair<int, int> curr );

int main(void) {
	scanf("%d", &n );

	for ( int i = 0; i < n; i++ )
		scanf("%s", grid[i]);

	vector<int> home;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ ) {
			if ( grid[i][j] - '0' )
				if ( !visited[i][j] ) {
					visited[i][j] = VISIT;
					home.push_back( bfs( { i, j } ) );
				}
			else
				visited[i][j] = VISIT;
		}

	sort( home.begin(), home.end() );

	int size = (int)home.size();
	printf("%d\n", size );
	for ( int i = 0; i < size; i++ )
		printf("%d\n", home[i] );

	return 0;
}

int bfs( pair<int, int> curr ) {
	int cnt = 0;
	queue<pair<int, int>> Q;

	Q.push( curr );
	while ( !Q.empty() ) {
		cnt++;
		pair<int, int> temp = Q.front(); Q.pop();

		pair<int, int> surr[4] = {
			{ temp.first - 1, temp.second },
			{ temp.first, temp.second - 1 },
			{ temp.first, temp.second + 1 },
			{ temp.first + 1, temp.second }
		};

		for ( int i = 0; i < 4; i++ ) {
			int row = surr[i].first, col = surr[i].second;
			if ( (0 <= row && row < n) && (0 <= col && col < n) )
				if ( !visited[row][col] && (grid[row][col] - '0') ) {
					visited[row][col] = VISIT;
					Q.push( surr[i] );
				}
		}
	}

	return cnt;
}