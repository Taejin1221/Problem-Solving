// Baekjoon20551_SuccessorOfSortMaster.cpp
// https://www.acmicpc.net/problem/20551
// IUPC B
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> arr( n );
	for ( int i = 0; i < n; i++ )
		cin >> arr[i];
	sort( arr.begin(), arr.end() );

	while ( m-- ) {
		int value;
		cin >> value;

		int idx = lower_bound( arr.begin(), arr.end(), value ) - arr.begin();

		if ( idx < n && arr[idx] == value )
			cout << idx;
		else
			cout << -1;
		cout << '\n';
	}

	return 0;
}