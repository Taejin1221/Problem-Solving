// Baekjoon01826_FillFuel.cpp
// https://www.acmicpc.net/problem/1826
#include <algorithm> /* sort() */
#include <iostream>
#include <queue> /* priority_queue<> */

using namespace std;

struct Station {
	int pos, oil;
};

bool compare( const Station& s1, const Station& s2 ) {
	return s1.pos < s2.pos;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	Station stations[10000];
	for ( int i = 0; i < n; i++ )
		cin >> stations[i].pos >> stations[i].oil;
	sort( stations, stations + n, compare );

	int target, possiblePos;
	cin >> target >> possiblePos;

	int time = 0, stationIdx = 0;
	priority_queue<int> pq;
	while ( possiblePos < target ) {
		while ( stationIdx < n && stations[stationIdx].pos <= possiblePos )
			pq.push( stations[stationIdx++].oil );

		if ( pq.empty() )
			break;
		else {
			time++;
			possiblePos += pq.top(); pq.pop();
		}
	}

	if ( target <= possiblePos )
		cout << time;
	else
		cout << -1;
	cout << '\n';

	return 0;
}