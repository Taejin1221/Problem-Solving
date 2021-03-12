// Baekjoon06603_Lotto.cpp
// https://www.acmicpc.net/problem/6603
#include <iostream>

#include <vector>

using namespace std;

int n;
int arr[13];
vector<vector<int>> ans;

void dfs( vector<int>& temp, int idx ) {
	if ( temp.size() == 6 )
		ans.push_back( temp );
	else {
		for ( int i = idx; i < n; i++ ) {
			temp.push_back( arr[i] );
			dfs( temp, i + 1 );
			temp.pop_back( );
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while ( n != 0 ) {
		for ( int i = 0; i < n; i++ )
			cin >> arr[i];

		ans.clear();
		vector<int> temp;
		dfs( temp, 0 );

		for ( int i = 0; i < ans.size(); i++ ) {
			for ( int& value : ans[i] )
				cout << value << ' ';
			cout << '\n';
		}
		cout << '\n';

		cin >> n;
	}

	return 0;
}