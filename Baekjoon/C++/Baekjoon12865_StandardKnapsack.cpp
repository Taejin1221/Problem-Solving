// Baekjoon12865_StandardKnapsack.cpp
// https://www.acmicpc.net/problem/12865
#include <iostream>

#define MAX_SIZE 100'001

using namespace std;

struct Object {
	int weight, value;
	Object( ): weight(0), value(0) {}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	Object objs[100];
	for ( int i = 0; i < n; i++ )
		cin >> objs[i].weight >> objs[i].value;

	int dp[MAX_SIZE][100] = { 0, };
	for ( int i = 1; i <= k; i++ ) {
		dp[i][0] = ( i < objs[0].weight ? 0 : objs[0].value );
		for ( int j = 1; j < n; j++ ) {
			if ( i < objs[j].weight )
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = max( dp[i][j - 1], dp[i - objs[j].weight][j - 1] + objs[j].value );
		}
	}

	cout << dp[k][n - 1] << '\n';

	return 0;
}