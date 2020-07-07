// Baekjoon13160_SolveMaxClick.cpp
// https://www.acmicpc.net/problem/13160
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Range {
	int s, e, i;
	Range() {}
	bool operator<( const Range& r2 ) const {
		if ( e != r2.e )
			return e > r2.e;
		else
			return s > r2.s;
	}
};

bool compare( const Range& r1, const Range& r2 ) {
	if ( r1.s != r2.s )
		return r1.s < r2.s;
	else
		return r1.e < r2.e;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	Range ranges[300000];
	for ( int i = 0; i < n; i++ ) {
		int s, e;
		cin >> s >> e;

		ranges[i].s = s;
		ranges[i].e = e;
		ranges[i].i = i + 1;
	}
	sort( ranges, ranges + n, compare );

	int maxVal = 0;
	priority_queue<Range> pq;
	for ( int i = 0; i < n; i++) {
		Range& currRange = ranges[i];

		while ( !pq.empty() && ( pq.top().e < currRange.s ) )
			pq.pop();
		pq.push( currRange );

		maxVal = ( maxVal < pq.size() ) ? pq.size() : maxVal;
	}

	pq = priority_queue<Range> ();
	for ( int i = 0; i < n; i++ ) {
		Range& currRange = ranges[i];

		while ( !pq.empty() && ( pq.top().e < currRange.s ) )
			pq.pop();
		pq.push( currRange );

		if ( pq.size() == maxVal )
			break;
	}

	cout << maxVal << '\n';
	while ( !pq.empty() ) {
		cout << pq.top().i << ' ';
		pq.pop();
	}
	cout << '\n';

	return 0;
}