// Baekjoon02306_Genetic.cpp
// https://www.acmicpc.net/problem/2306
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	char dna[501];
	cin >> dna;

	int n = strlen( dna );

	int maxVal = 0;
	int dp[501][501] = { 0, };
	for ( int i = 1; i < n; i++ ) {
		for ( int j = 0; j < n - i; j++ ) {
			int r = j, c = i + j;
			if ( (dna[r] == 'a' && dna[c] == 't') || (dna[r] == 'g' && dna[c] == 'c') )
				dp[r][c] += 2 + dp[r + 1][c - 1];

			for ( int k = r; k < c; k++ )
				dp[r][c] = max( dp[r][c], dp[r][k] + dp[k + 1][c] );

			maxVal = ( maxVal < dp[r][c] ) ? dp[r][c] : maxVal;
		}
	}

	cout << maxVal << '\n';

	return 0;
}