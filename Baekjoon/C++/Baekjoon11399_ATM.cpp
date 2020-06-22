// Baekjoon11399_ATM.cpp
// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm> /* sort() */

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int minutes[1000];
	for ( int i = 0; i < n; i++ )
		cin >> minutes[i];
	sort( minutes, minutes + n );

	int sum = minutes[0];
	for ( int i = 1; i < n; i++ ) {
		minutes[i] += minutes[i - 1];
		sum += minutes[i];
	}

	cout << sum << '\n';

	return 0;
}