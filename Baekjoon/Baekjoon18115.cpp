// Baekjoon18115_PlaceCard.cpp
// https://www.acmicpc.net/problem/18115
#include <iostream>
#include <deque>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int opers[1'000'000];
	for ( int i = 0; i < n; i++ )
		cin >> opers[i];

	deque<int> dq;
	int num = 1;
	for ( int i = n - 1; i >= 0; i-- ) {
		if ( opers[i] == 1 )
			dq.push_front( num );
		else if ( opers[i] == 2 ) {
			int temp = dq.front(); dq.pop_front();
			dq.push_front( num );
			dq.push_front( temp );
		} else
			dq.push_back( num );

		num++;
	}

	for ( auto iter = dq.begin(); iter != dq.end(); ++iter )
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}