// Baekjoon14215.cpp
// https://www.acmicpc.net/problem/14215
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	int longStick = max(a, max(b, c));

	int shortSum = a + b + c - longStick;
	if (shortSum <= longStick)
		cout << shortSum * 2 - 1;
	else
		cout << a + b + c;
	cout << '\n';

	return 0;
}