// Baekjoon01049_GuitarString.cpp
// https://www.acmicpc.net/problem/1049
#include <iostream>

#include <algorithm>

#define INF 1234567890

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int price[50][2];
	for ( int i = 0; i < m; i++ )
		cin >> price[i][0] >> price[i][1];

	int string[101];
	fill( string, string + n + 1, INF );

	string[0] = 0;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j < m; j++ ) {
			string[i] = min( string[i], string[i - 1] + price[j][1] );

			if ( i >= 6 )
				string[i] = min( string[i], string[i - 6] + price[j][0] );
			else
				string[i] = min( string[i], string[0] + price[j][0] );
		}
	}

	cout << string[n] << '\n';

	return 0;
}