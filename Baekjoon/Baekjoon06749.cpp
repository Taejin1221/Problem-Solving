// Baekjoon06749_NextInLine.cpp
// https://www.acmicpc.net/problem/6749
#include <iostream>

using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	cout << b + ( b - a ) << '\n';

	return 0;
}