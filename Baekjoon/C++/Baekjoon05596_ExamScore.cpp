// Baekjoon05596_ExamScore.cpp
// https://www.acmicpc.net/problem/5596
#include <iostream>

using namespace std;

int main(void) {
	int s = 0, t = 0;

	for ( int i = 0; i < 4; i++ ) {
		int temp;
		cin >> temp;

		s += temp;
	}

	for ( int j = 0; j < 4; j++ ) {
		int temp;
		cin >> temp;

		t += temp;
	}

	cout << (( s < t ) ? t : s) << '\n';

	return 0;
}