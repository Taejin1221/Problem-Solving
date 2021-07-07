// Baekjoon02953_IAmCooker.cpp
// https://www.acmicpc.net/problem/2953
#include <iostream>

using namespace std;

int main(void) {
	int winner, score = 0;
	for ( int i = 0; i < 5; i++ ) {
		int sum = 0;
		for ( int j = 0; j < 4; j++ ) {
			int temp;
			cin >> temp;
			sum += temp;
		}

		if ( score < sum ) {
			score = sum;
			winner = i + 1;
		}
	}

	cout << winner << ' ' << score << '\n';

	return 0;
}
