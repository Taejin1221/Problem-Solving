// Baekjoon02629_Balances.cpp
// https://www.acmicpc.net/problem/2629
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int weights[30], sum = 0;
	for ( int i = 0; i < n; i++ ) {
		cin >> weights[i];
		sum += weights[i];
	}

	bool dp[15'001][30] = { false, };
	for ( int i = 1; i <= sum; i++ ) {
		if ( i == weights[0] )
			dp[i][0] = true;

		for ( int j = 1; j < n; j++ ) {
			if ( i > weights[j] )
				dp[i][j] = dp[i][j - 1] || dp[i - weights[j]][j - 1];
			else if ( i == weights[j] )
				dp[i][j] = true;
			else
				dp[i][j] = dp[i][j - 1];
		}
	}

	int m;
	cin >> m;

	for ( int time = 0; time < m; time++ ) {
		int marble;
		cin >> marble;

		int canWeigh = false;
		for ( int i = marble; i <= sum; i++ ) {
			if ( dp[i][n - 1] && ( i == marble || dp[i - marble][n - 1] ) ) {
				canWeigh = true;
				break;
			}
		}

		if ( canWeigh )
			cout << "Y ";
		else
			cout << "N ";
	}
	cout << '\n';

	return 0;
}