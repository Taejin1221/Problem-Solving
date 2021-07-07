// Baekjoon13458_ExamDirector.cpp
// https://www.acmicpc.net/problem/13458
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int people[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> people[i];

	int b, c;
	cin >> b >> c;

	long long ans = 0;
	for ( int i = 0; i < n; i++ ) {
		people[i] -= b;

		ans++;
		if ( people[i] > 0 )
			ans += (long long)ceil( (double)people[i] / c );
	}

	cout << ans << '\n';

	return 0;
}
