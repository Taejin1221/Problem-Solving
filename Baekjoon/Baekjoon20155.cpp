// Baekjoon20155_ConvinienceStoreUnderMyHome.cpp
// https://www.acmicpc.net/problem/20155
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int arr[1'001] = { 0, };
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		arr[temp]++;
	}

	int ans = 0;
	for ( int i = 1; i <= m; i++ )
		ans = max( ans, arr[i] );

	cout << ans << '\n';

	return 0;
}