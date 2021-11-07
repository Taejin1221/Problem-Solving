// Baekjoon04892.cpp
// https://www.acmicpc.net/problem/4892
#include <iostream>

using namespace std;

int main(void) {
	int n_0, time = 1;
	cin >> n_0;
	while (n_0) {
		cout << time << ". ";

		n_0 *= 3;
		if (n_0 % 2) {
			cout << "odd ";
			n_0 = (n_0 + 1) / 2;
		} else {
			cout << "even ";
			n_0 = n_0 / 2;
		}

		n_0 *= 3;
		n_0 /= 9;

		cout << n_0 << '\n';

		cin >> n_0;
		time++;
	}

	return 0;
}