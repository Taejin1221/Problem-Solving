// Baekjoon20044_ProjectTeams.cpp
// https://www.acmicpc.net/problem/20044
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	n *= 2;
	int students[10000];
	for ( int i = 0 ; i < n; i++ )
		cin >> students[i];

	sort( students, students + n );

	int ans = 200'000 * 5'000;
	for ( int i = 0; i < n / 2; i++ )
		ans = min( ans, students[i] + students[n - i - 1] );

	cout << ans << '\n';

	return 0;
}
