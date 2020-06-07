// Baekjoon02579_ClimbingStair.cpp
// https://acmicpc.net/problem/2579
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int num;
	cin >> num;

	vector<int> stairScore ( num );
	for ( int i = 0; i < num; i++ )
		cin >> stairScore[i];

	vector<vector<int>> table;
	table.push_back( vector<int> { stairScore[0], stairScore[0] } );
	table.push_back( vector<int> { stairScore[1], stairScore[0] + stairScore[1] } );
	for ( int n = 2; n < num; n++ ) {
		vector<int> temp;
		temp.push_back( stairScore[n] + table[n - 2][1] );
		temp.push_back( stairScore[n] + max( table[n - 1][0], table[n - 2][1] ) );
		table.push_back( temp );
	}

	cout << max( table[num - 1][0], table[num - 1][1] ) << "\n";

	return 0;
}
