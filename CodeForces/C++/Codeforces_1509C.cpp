// Codeforces_1509C.cpp
#include <iostream>
#include <algorithm>

#define MAX_SIZE 2'000

using namespace std;

void solveTestCase( ) {
	int n;
	cin >> n;

	int arr[MAX_SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	long long dp[MAX_SIZE][MAX_SIZE] = { 0, };

	for ( int interval = 1; interval < n; interval++ ) {
		for ( int row = 0; row < n - interval; row++ ) {
			int col = row + interval;
			dp[row][col] = arr[col] - arr[row] + min( dp[row + 1][col], dp[row][col - 1] );
		}
	}

	cout << dp[0][n - 1] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
