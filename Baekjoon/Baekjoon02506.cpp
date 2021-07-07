// Baekjoon02506_SumScore.cpp
// https://www.acmicpc.net/problem/2506
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int sum = 0, score = 1;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		if ( temp )
			sum += score++;
		else
			score = 1;
	}

	cout << sum << '\n';

	return 0;
}