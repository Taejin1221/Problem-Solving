// Baekjoon02473_ThreeLiquid.cpp
// https://www.acmicpc.net/problem/2473
#include <iostream>

#include <algorithm>

#define ABS( a ) ( ( ( a ) < 0l ) ? ( -( a ) ) : ( a ) )

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[5'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	int ans[3];
	long sum = 3'000'000'000L;
	for ( int fix = 0; fix < n - 2; fix++ ) {
		int i = fix + 1, j = n - 1;
		while ( j < n && i < j ) {
			long newSum = ABS((long)arr[fix] + arr[i] + arr[j]);
			if ( newSum < sum ) {
				ans[0] = arr[fix], ans[1] = arr[i], ans[2] = arr[j];
				sum = newSum;
			}

			if ( arr[i] + arr[j] < -arr[fix] )
				i++;
			else
				j--;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

	return 0;
}