// Baekjoon05554_Errand.cpp
// https://www.acmicpc.net/problem/5554
#include <iostream>

using namespace std;

int main(void) {
	int sum = 0;

	for ( int i = 0; i < 4; i++ ) {
		int temp;
		cin >> temp;

		sum += temp;
	}

	cout << sum / 60 << '\n';
	cout << sum % 60 << '\n';

	return 0;
}