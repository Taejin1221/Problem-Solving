// Baekjoon04307_Ant.cpp
// https://www.acmicpc.net/problem/4307
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int l, n;
		cin >> l >> n;

		int minAnt = 1'000'000, maxAnt = 0, minAns = 0;
		for ( int i = 0; i < n; i++ ) {
			int ant;
			cin >> ant;

			minAnt = min( minAnt, ant );
			maxAnt = max( maxAnt, ant );

			if ( ant < l / 2 )
				minAns = max( minAns, ant );
			else
				minAns = max( minAns, l - ant );
		}

		cout << minAns << ' ';
		cout << max( l - minAnt, maxAnt ) << '\n';
	}

	return 0;
}