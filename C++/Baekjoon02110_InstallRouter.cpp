// Baekjoon02110_InstallRouter.cpp
// https://www.acmicpc.net/problem/2110
#include <algorithm> /* sort() */
#include <iostream>

using namespace std;

int n, c;
int homes[200000];

int Router( int dis ) {
	int sum = 1, prevIdx = 0;
	for ( int currIdx = 1; currIdx < n; currIdx++ ) {
		if ( (homes[currIdx] - homes[prevIdx]) >= dis ) {
			prevIdx = currIdx;
			sum++;
		}
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> c;
	
	for ( int i = 0; i < n; i++ )
		cin >> homes[i];
	sort( homes, homes + n );

	int left = 1, right = homes[n - 1] - homes[0];
	while ( left + 1 < right ) {
		int mid = ( right + left ) / 2;
		if ( Router( mid ) >= c )
			left = mid;
		else
			right = mid;
	}

	cout << left << '\n';

	return 0;
}