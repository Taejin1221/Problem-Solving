// Baekjoon01806_Subsequence.cpp
// https://www.acmicpc.net/problem/1806
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	int arr[100'000];
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	int ans = 100'000;
	int i = 0, j = 0, sum = arr[0];
	while ( j < n ) {
		if ( sum < s ) {
			j++;
			sum += arr[j];
		} else {
			ans = min( ans, j - i + 1 );
			sum -= arr[i];
			i++;
		}
	}

	if ( i != 0 )
		cout << ans << '\n';
	else
		cout << 0 << '\n';

	return 0;
}