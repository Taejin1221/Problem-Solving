// Baekjoon01026_Treasure.cpp
// https://www.acmicpc.net/problem/1026
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a[50], b[50];
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
	for ( int i = 0; i < n; i++ )
		cin >> b[i];

	sort( a, a + n );
	sort( b, b + n );

	int ans = 0;
	for ( int i = 0; i < n; i++ ) {
		ans += a[i] * b[n - i - 1];
	}

	cout << ans << '\n';

	return 0;
}