// Baekjoon05565_Receipt.cpp
// https://www.acmicpc.net/problem/5565
#include <iostream>

using namespace std;

int main(void) {
	int sum = 0;

	int total;
	cin >> total;
	for ( int i = 0; i < 9; i++ ) {
		int temp;
		cin >> temp;

		sum += temp;
	}

	cout << total - sum << '\n';

	return 0;
}