// Baekjoon15953_PrizeHunter.cpp
// https://www.acmicpc.net/problem/15953
#include <iostream>

using namespace std;

int main(void) {
	int first[6][2] = {
		{ 1, 500 },
		{ 3, 300 },
		{ 6, 200 },
		{ 10, 50 },
		{ 15, 30 },
		{ 21, 10 }
	};

	int second[5][2] = {
		{ 1, 512 },
		{ 3, 256 },
		{ 7, 128 },
		{ 15, 64 },
		{ 31, 32 }
	};

	int t;
	cin >> t;
	while ( t-- ) {
		int a, b;
		cin >> a >> b;

		int prize = 0;
		if ( a != 0 ) {
			for ( int i = 0; i < 6; i++ ) {
				if ( a <= first[i][0] ) {
					prize += first[i][1];
					break;
				}
			}
		}

		if ( b != 0 ) {
			for ( int i = 0; i < 5; i++ ) {
				if ( b <= second[i][0] ) {
					prize += second[i][1];
					break;
				}
			}
		}

		prize *= 10000;
		cout << prize << '\n';
	}

	return 0;
}