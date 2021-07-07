// Baekjoon10971_TravelingSalesmanProblem.cpp
// https://www.acmicpc.net/problem/10971
#include <iostream>

#include <vector>

#define INF 1'000'000'000

using namespace std;

int n, ans = INF;
int weights[10][10];
bool visited[10];
vector<int> cities;

void backtracking( int currWeight ) {
	if ( cities.size() == n )
		ans = min( ans, currWeight + weights[cities.back()][cities.front()] );
	else {
		for ( int i = 0; i < n; i++ ) {
			if ( !visited[i] ) {
				int nextWeight = 0;
				if ( !cities.empty() )
					nextWeight = currWeight + weights[cities.back()][i];

				if ( nextWeight < INF ) {
					visited[i] = true;
					cities.push_back( i );
					backtracking( nextWeight );
					visited[i] = false;
					cities.pop_back( );
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			cin >> weights[i][j];
			if ( !weights[i][j] )
				weights[i][j] = INF;
		}
	}

	backtracking( 0 );

	cout << ans << '\n';
}