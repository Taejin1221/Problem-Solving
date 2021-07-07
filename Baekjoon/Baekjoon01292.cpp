// Baekjoon01292_EasyProblem.cpp
// https://www.acmicpc.net/problem/1292
#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	int sum = 0, number = 1, time = 0;
	bool isAdd = false;
	for ( int i = 1; i <= b; i++ ) {
		if ( i == a )
			isAdd = true;

		if ( isAdd )
			sum += number;

		time++;
		if ( time == number ) {
			number++;
			time = 0;
		}
	}

	cout << sum << '\n';

	return 0;
}