// Baekjoon02490_PlayingYut.cpp
// https://www.acmicpc.net/problem/2490
#include <iostream>

using namespace std;

int GetCount0( int arr[] ) {
	int count = 0;
	for ( int i = 0; i < 4; i++ )
		if ( !arr[i] )
			count++;

	return count;
}

int main(void) {
	int arr[4];
	for ( int i = 0; i < 3; i++ ) {
		for ( int j = 0; j < 4; j++ )
			cin >> arr[j];

		int count0 = GetCount0(arr);

		if ( count0 == 1 )
			cout << 'A';
		else if ( count0 == 2 )
			cout << 'B';
		else if ( count0 == 3 )
			cout << 'C';
		else if ( count0 == 4 )
			cout << 'D';
		else
			cout << 'E';
		cout << '\n';
	}

	return 0;
}