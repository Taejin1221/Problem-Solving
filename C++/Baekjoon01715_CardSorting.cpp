// Baekjoon01715_CardSorting.cpp
// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie( NULL );

	priority_queue<int, vector<int>, greater<int> > pq;

	int time;
	cin >> time;
	while ( time-- ) {
		int num;
		cin >> num;

		pq.push( num );
	}

	int compare = 0;
	while ( pq.size() != 1 ) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		compare += (a + b);
		pq.push( a + b );
	}

	cout << compare << '\n';

	return 0;
}