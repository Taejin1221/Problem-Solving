// Baekjoon15655_NandM6.cpp
// https://www.acmicpc.net/problem/15655
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[8], n, m;
vector< vector<int> > ans;

void backtracking( vector<int>& curr, int idx ) {
	if ( curr.size() == m )
		ans.push_back( curr );
	else {
		for ( int i = idx; i < n; i++ ) {
			curr.push_back( arr[i] );
			backtracking( curr, i + 1 );
			curr.pop_back( );
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	vector<int> curr;
	backtracking( curr, 0 );

	for ( vector<int>& sequence : ans ) {
		for ( int& value : sequence )
			cout << value << ' ';
		cout << '\n';
	}

	return 0;
}