// Baekjoon03003_KingQueenRookBishopKnightPawn.cpp
// https://www.acmicpc.net/problem/3003
#include <iostream>

using namespace std;

int main(void) {
	int chess[6] = { 1, 1, 2, 2, 2, 8 };

	for ( int i = 0; i < 6; i++ ) {
		int temp;
		cin >> temp;

		cout << chess[i] - temp << ' ';
	}
	cout << '\n';

	return 0;
}