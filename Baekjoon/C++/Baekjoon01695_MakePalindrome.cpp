// Baekjoon01695_MakePalindrome.cpp
// https://www.acmicpc.net/problem/1695
#include <iostream>

#define SIZE 5'000

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[SIZE];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int dp[SIZE][SIZE] = { 0, };
	for ( int dis = 1; dis < n; dis++ ) {
		for ( int i = 0; i < n - dis; i++ ) {
			int j = i + dis;
			if ( arr[i] == arr[j] )
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min( dp[i + 1][j], dp[i][j - 1] ) + 1;
		}
	}

	cout << dp[0][n - 1] << '\n';

	return 0;
}