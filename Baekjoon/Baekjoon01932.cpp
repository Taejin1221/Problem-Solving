// Baekjoon01932_IntegerTrianble.cpp
// https://www.acmicpc.net/problem/1932
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie( NULL );

	int n;
	cin >> n;
	int triangle[500][500];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j <= i; j++ ) {
			cin >> triangle[i][j];
		}

	int maxPath[500][500];
	for ( int i = 0; i < n; i++ )
		maxPath[n - 1][i] = triangle[n - 1][i];


	for ( int i = n - 2; i >= 0; i-- ) {
		for ( int j = 0; j <= i; j++ ) {
			maxPath[i][j] = triangle[i][j] + max( maxPath[i + 1][j], maxPath[i + 1][j + 1] );
		}
	}

	cout << maxPath[0][0] << '\n';

	return 0;
}
