// Baekjoon02875_ChallengeOrIntern.cpp
// https://www.acmicpc.net/problem/2875
#include <iostream>

using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	for ( int internWoman = 0; internWoman <= k; internWoman++ ) {
		int woman = internWoman, man = k - internWoman;

		ans = max( ans, min( (n - woman) / 2, m - man ) );
	}

	cout << ans << '\n';

	return 0;
}
