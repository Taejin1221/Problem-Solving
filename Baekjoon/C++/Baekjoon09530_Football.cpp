// Baekjoon09530_Football.cpp
// https://www.acmicpc.net/problem/9530
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, goal;
	cin >> n >> goal;

	int scores[100'000];
	for ( int i = 0; i < n; i++ ) {
		int score, receive;
		cin >> score >> receive;

		scores[i] = score - receive;
	}

	sort( scores, scores + n, greater<int> () );

	int ans = 0;
	for ( int i = 0; i < n; i++ ) {
		if ( goal > 0 ) {
			if ( scores[i] > 0 )
				ans += 3;
			else if ( scores[i] == 0 ) {
				goal--;
				ans += 3;
			} else {
				if ( -scores[i] == goal ) {
					goal += scores[i];
					ans += 1;
				} else if ( -scores[i] < goal) {
					goal += scores[i] - 1;
					ans += 3;
				}
			}
		} else {
			if ( scores[i] == 0 )
				ans++;
			else if ( scores[i] > 0 )
				ans += 3;
		}
	}

	cout << ans << '\n';

	return 0;
}