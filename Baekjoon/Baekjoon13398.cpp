// Baekjoon13398_ContiguousSum2.cpp
// https://www.acmicpc.net/problem/13398
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int ans = -1000;

	int arr[100'000];
	for ( int i = 0; i < n; i++ ) {
		cin >> arr[i];
		ans = max( ans, arr[i] );
	}

	int curr = 0, currDel = 0;
	for ( int i = 0; i < n; i++ ) {
		currDel = max( max( curr, currDel + arr[i] ), 0 );
		curr = max( curr + arr[i], 0 );

		int maxCurr = max( curr, currDel );
		if ( maxCurr > 0 )
			ans = max( ans, maxCurr );
	}

	cout << ans << '\n';

	return 0;
}