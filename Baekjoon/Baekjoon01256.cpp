// Baekjoon01256_Dictionary.cpp
// https://www.acmicpc.net/problem/1256
#include <iostream>

#define INF 1'000'000'001l

using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;

	long dp[201][201];

	dp[0][0] = 1l;
	dp[1][0] = 1l;
	dp[1][1] = 1l;

	for ( int i = 2; i <= n + m; i++ ) {
		dp[i][0] = 1;
		for ( int j = 1; j < i; j++ )
			dp[i][j] = min( dp[i - 1][j] + dp[i - 1][j - 1], INF );
		dp[i][i] = 1;
	}

	if ( dp[n + m][n] < k )
		cout << -1;
	else {
		int a = n, z = m;
		for ( int i = 0; i < n + m; i++ ) {
			if ( a == 0 )
				cout << 'z';
			else if ( z == 0 )
				cout << 'a';
			else {
				int total = a + z - 1;
				if ( dp[total][z] >= k ) {
					cout << 'a';
					a--;
				} else {
					cout << 'z';
					k -= dp[total][z]; 
					z--;
				}
			}
		}
	}

	cout << '\n';

	return 0;
}