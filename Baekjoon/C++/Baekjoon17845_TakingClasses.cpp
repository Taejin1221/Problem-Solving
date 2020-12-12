// Baekjoon17845_TakingClasses.cpp
// https://www.acmicpc.net/problem/17845
#include <iostream>

using namespace std;

#define MAX_ROW 1001
#define MAX_COL 100

struct Class {
	int importance, time;
	Class(): importance(0), time(0) { }
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	Class classes[1'000];
	for ( int i = 0; i < k; i++ )
		cin >> classes[i].importance >> classes[i].time;

	// row -> time, col -> class
	int dp[MAX_ROW][MAX_COL] = { 0, };
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 0; j < k; j++ ) {
			if ( i >= classes[j].time ) {
				if ( j == 0 )
					dp[i][j] = classes[j].importance;
				else
					dp[i][j] = max( dp[i][j - 1], dp[i - classes[j].time][j - 1] + classes[j].importance );
			}
			else {
				if ( j != 0 )
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	cout << dp[n][k - 1] << '\n';

	return 0;
}
