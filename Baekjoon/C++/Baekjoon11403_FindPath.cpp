// Baekjoon11403_FindPath.cpp
// https://www.acmicpc.net/problem/11403
#include <iostream>

#define MAX_ARR_SIZE 100

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	bool adjMatrix[MAX_ARR_SIZE][MAX_ARR_SIZE];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> adjMatrix[i][j];

	for ( int k = 0; k < n; k++ )
		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				if ( adjMatrix[i][k] && adjMatrix[k][j] )
					adjMatrix[i][j] = true;

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ )
			cout << adjMatrix[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}