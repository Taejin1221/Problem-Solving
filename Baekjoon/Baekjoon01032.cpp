// Baekjoon01032_Command.cpp
// https://www.acmicpc.net/problem/1032
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string strs[50];
	for ( int i = 0; i < n; i++ )
		cin >> strs[i];

	vector<char> ansVector;
	for ( int i = 0; i < strs[0].size(); i++ ) {
		bool question = false;
		char threshold = strs[0][i];
		for ( int j = 1; j < n; j++ ) {
			if ( strs[j][i] != threshold ) {
				question = true;
				break;
			}
		}

		if ( question )
			ansVector.push_back( '?' );
		else
			ansVector.push_back( threshold );
	}

	for ( int i = 0; i < ansVector.size(); i++ )
		cout << ansVector[i];
	cout << '\n';

	return 0;
}