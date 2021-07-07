// Baekjoon17435_CompositeFunctionAndQuery.cpp
// https://www.acmicpc.net/problem/17435
#include <iostream>

#define endl '\n'
#define MAX_ARR_SIZE 200'001
#define MAX_ROW 20

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int m;
	cin >> m;

	int table[MAX_ROW][MAX_ARR_SIZE] = { 0, };
	for ( int i = 1; i <= m; i++ )
		cin >> table[0][i];

	for ( int j = 1; j < MAX_ROW; j++ )
		for ( int i = 1; i <= m; i++ )
			table[j][i] = table[j - 1][table[j - 1][i]];

	int q;
	cin >> q;
	while ( q-- ) {
		int n, x;
		cin >> n >> x;

		for ( int i = 0; i < MAX_ROW; i++ )
			if ( n & (1 << i) )
				x = table[i][x];

		cout << x << endl;
	}

	return 0;
}