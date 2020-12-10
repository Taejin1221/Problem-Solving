// Baekjoon01946_NewRecruit.cpp
// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <algorithm>

using namespace std;

struct Score {
	int paper, meet;
	bool operator<( const Score& s2 ) const {
		return paper < s2.paper;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;

		Score scores[100'000];
		for ( int i = 0; i < n; i++ )
			cin >> scores[i].paper >> scores[i].meet;

		sort( scores, scores + n );

		int count = 1;
		int minMeet = scores[0].meet;
		for ( int i = 1; i < n; i++ ) {
			if ( minMeet > scores[i].meet ) {
				count++;
				minMeet = scores[i].meet;
			}
		}

		cout << count << '\n';
	}

	return 0;
}
