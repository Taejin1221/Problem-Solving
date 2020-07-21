// Baekjoon01764_Stranger.cpp
// https://www.acmicpc.net/problem/1764
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> table;
	vector<string> hearsee;
	for ( int i = 1; i <= n; i++ ) {
		string temp;
		cin >> temp;

		table[temp] = i;
	}

	for ( int j = 0; j < m; j++ ) {
		string temp;
		cin >> temp;

		if ( table[temp] )
			hearsee.push_back( temp );
	}
	sort( hearsee.begin(), hearsee.end() );

	cout << hearsee.size() << '\n';
	for ( int i = 0; i < hearsee.size(); i++ )
		cout << hearsee[i] << '\n';

	return 0;
}