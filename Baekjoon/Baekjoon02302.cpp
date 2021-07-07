// Baekjoon02302_TheaterSeat.
// https://www.acmicpc.net/problem/2302
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int dp[41] = { 1, 1, 2, };
	for ( int i = 2; i <= 40; i++ )
		dp[i] = dp[i - 1] + dp[i - 2];

	int n, m;
	cin >> n >> m;

	int ans = 1;
	int prev, next = -1;
	for ( int i = 0; i < m; i++ ) {
		prev = next;
		cin >> next;
		next--;
		if ( next - prev >= 1 )
			ans *= dp[next - prev - 1];
	}
	ans *= dp[n - next - 1];

	cout << ans << '\n';

	return 0;
}
