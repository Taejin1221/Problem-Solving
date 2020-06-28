// Baekjoon04195_VirtualFriends.cpp
// https://www.acmicpc.net/problem/4195
#include <iostream>
#include <string>
#include <map>

using namespace std;

pair<int, int> parents[200001];

int FindRoot( int a );
int Union( int a, int b );

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while ( t-- ) {
		int friendIdx = 1;
		map<string, int> nameTable;

		int f; cin >> f;
		for ( int i = 0; i < f; i++ ) {
			int f1_idx, f2_idx;
			string f1, f2;

			cin >> f1;
			auto f1_iter = nameTable.find( f1 );
			if ( f1_iter->second >= friendIdx ) {
				nameTable.insert( make_pair( f1, friendIdx ) );

				parents[friendIdx].first = friendIdx;
				parents[friendIdx].second = 1;

				f1_idx = friendIdx++;
			} else
				f1_idx = f1_iter->second;

			cin >> f2;
			auto f2_iter = nameTable.find( f2 );
			if ( f2_iter->second >= friendIdx ) {
				nameTable.insert( make_pair( f2, friendIdx ) );

				parents[friendIdx].first = friendIdx;
				parents[friendIdx].second = 1;

				f2_idx = friendIdx++;
			} else
				f2_idx = f2_iter->second;

			cout << Union( f1_idx, f2_idx ) << '\n';
		}
	}

	return 0;
}

int FindRoot( int a ) {
	if ( parents[a].first == a )
		return a;
	else
		return parents[a].first = FindRoot( parents[a].first );
}

int Union( int a, int b ) {
	int aRoot = FindRoot( a );
	int bRoot = FindRoot( b );

	if ( aRoot == bRoot )
		return parents[aRoot].second;
	else if ( aRoot < bRoot ) {
		parents[bRoot].first = aRoot;
		parents[aRoot].second += parents[bRoot].second;

		return parents[aRoot].second;
	} else if ( aRoot > bRoot ) {
		parents[aRoot].first = bRoot;
		parents[bRoot].second += parents[aRoot].second;

		return parents[bRoot].second;
	}
}