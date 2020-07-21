// Baekjoon10798_VerticalRead.cpp
// https://www.acmicpc.net/problem/10798
#include <iostream>

using namespace std;

int main(void) {
	char strs[5][16] = { 0, };
	for ( int i = 0; i < 5; i++ )
		cin >> strs[i];

	for ( int i = 0; i < 16; i++ )
		for ( int j = 0; j < 5; j++ )
			if ( strs[j][i] )
				cout << strs[j][i];
	cout << '\n';

	return 0;
}