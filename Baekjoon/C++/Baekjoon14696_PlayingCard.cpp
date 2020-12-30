// Baekjoon14696_PlayingCard.cpp
// https://www.acmicpc.net/problem/14696
// KOI 2017 초등부 1
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while ( t-- ) {
		int aNum, bNum;
		int aCards[5] = { 0, }, bCards[5] = { 0, };

		cin >> aNum;
		for ( int i = 0; i < aNum; i++ ) {
			int temp;
			cin >> temp;

			aCards[temp]++;
		}

		cin >> bNum;
		for ( int i = 0; i < bNum; i++ ) {
			int temp;
			cin >> temp;

			bCards[temp]++;
		}

		char win = 'D';
		for ( int i = 4; i > 0; i-- ) {
			if ( aCards[i] != bCards[i] ) {
				win = ( aCards[i] > bCards[i] ) ? 'A' : 'B';
				break;
			}
		}

		cout << win << '\n';
	}

	return 0;
}
