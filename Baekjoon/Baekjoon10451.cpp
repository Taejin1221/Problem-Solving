// Baekjoon10451_PermutationCycles.cpp
// https://www.acmicpc.net/problem/10451
#include <iostream>
#include <algorithm>

using namespace std;

int n, permutation[1'001];
bool visited[1'001];

void dfs( int curr ) {
	int next = permutation[curr];
	if ( !visited[next] ) {
		visited[next] = true;
		dfs( next );
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		cin >> n;
		for ( int i = 1; i <= n; i++ )
			cin >> permutation[i];

		fill( visited + 1, visited + n + 1, false );

		int ans = 0;
		for ( int i = 1; i <= n; i++ ) {
			if ( !visited[i] ) {
				visited[i] = true;
				dfs( i );
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}