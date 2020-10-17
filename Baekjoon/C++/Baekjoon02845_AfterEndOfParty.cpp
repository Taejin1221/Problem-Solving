// Baekjoon02845_AfterEndOfParty.cpp
// https://www.acmicpc.net/problem/2845
#include <iostream>

using namespace std;

int main(void) {
	int l, p;
	cin >> l >> p;

	int answer = l * p;

	for ( int i = 0; i < 5; i++ ) {
		int curr;
		cin >> curr;

		cout << curr - answer << ' ';
	}
	cout << '\n';

	return 0;
}