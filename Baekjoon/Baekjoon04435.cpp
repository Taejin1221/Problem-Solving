// Baekjoon04435.cpp
// https://www.acmicpc.net/problem/4435
#include <iostream>

using namespace std;

int main(void) {
	const int good[6] = { 1, 2, 3, 3, 4, 10 };
	const int evil[7] = { 1, 2, 2, 2, 3, 5, 10 };

	int t;
	cin >> t;
	for (int time = 1; time <= t; time++) {
		int currGood = 0, currEvil = 0;

		int temp;
		for (int i = 0; i < 6; i++) {
			cin >> temp;

			currGood += temp * good[i];
		}

		for (int i = 0; i < 7; i++) {
			cin >> temp;

			currEvil += temp * evil[i];
		}

		cout << "Battle " << time << ": ";
		if (currGood > currEvil)
			cout << "Good triumphs over Evil";
		else if (currGood < currEvil)
			cout << "Evil eradicates all trace of Good";
		else
			cout << "No victor on this battle field";
		cout << '\n';
	}

	return 0;
}