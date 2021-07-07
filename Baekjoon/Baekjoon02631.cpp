// Baekjoon02631_Line.cpp
// https://www.acmicpc.net/problem/2631
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[200];
	int dp[200];
	for ( int i = 0; i < n; i++ ) {
		cin >> arr[i];
		dp[i] = 1;
	}

	int maxVal = 0;
	for ( int i = n - 2; i >= 0; i-- ) {
		for ( int j = i + 1; j < n; j++ ) {
			if ( arr[j] > arr[i] )
				dp[i] = max( dp[i], dp[j] + 1 );
		}
		maxVal = ( maxVal < dp[i] ) ? dp[i] : maxVal;
	}

	cout << n - maxVal << '\n';

	return 0;
}