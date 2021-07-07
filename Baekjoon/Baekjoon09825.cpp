// Baekjoon09825_BABBA.cpp
// https://www.acmicpc.net/problem/9625
#include <iostream>

using namespace std;

int main(void) {
	int k;
	cin >> k;

	int currA = 1, currB = 0;
	for ( int i = 0; i < k; i++ ) {
		int nextA = currB, nextB = currA + currB;

		currA = nextA, currB = nextB;
	}

	cout << currA << ' ' << currB << '\n';

	return 0;
}