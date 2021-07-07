// Baekjoon05522_CardGame.cpp
// https://www.acmicpc.net/problem/5522
#include <iostream>

using namespace std;

int main(void) {
	int sum = 0;

	for ( int i = 0; i < 5; i++ ) {
		int temp;
		cin >> temp;

		sum += temp;
	}

	cout << sum << '\n';

	return 0;
}