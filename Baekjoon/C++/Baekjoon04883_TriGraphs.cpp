// Baekjoon04883_TriGraphs.cpp
// https://www.acmicpc.net/problem/4883
#include <iostream>

using namespace std;

int min( int a, int b, int c ) {
	return min( a , min( b, c ) );
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, time = 1;
	cin >> n;
	while ( n != 0 ) {
		int prevDp[3], currDp[3];
		cin >> prevDp[0] >> prevDp[1] >> prevDp[2];
		cin >> currDp[0] >> currDp[1] >> currDp[2];

		prevDp[2] += prevDp[1];

		currDp[0] += prevDp[1];
		currDp[1] += min( currDp[0], prevDp[1], prevDp[2] );
		currDp[2] += min( currDp[1], prevDp[1], prevDp[2] );

		prevDp[0] = currDp[0];
		prevDp[1] = currDp[1];
		prevDp[2] = currDp[2];

		for ( int i = 2; i < n; i++ ) {
			cin >> currDp[0] >> currDp[1] >> currDp[2];

			currDp[0] += min( prevDp[0], prevDp[1] );
			currDp[1] += min( currDp[0], min( prevDp[0], prevDp[1], prevDp[2] ) );
			currDp[2] += min( currDp[1], prevDp[1], prevDp[2] );

			prevDp[0] = currDp[0];
			prevDp[1] = currDp[1];
			prevDp[2] = currDp[2];
		}

		cout << time << ". " << prevDp[1] << '\n';

		cin >> n;
		time++;
	}

	return 0;
}