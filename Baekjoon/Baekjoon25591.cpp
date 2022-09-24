// Baekjoon25591.cpp
// https://www.acmicpc.net/problem/25591
#include <iostream>

using namespace std;

int main(void) {
	int num1, num2;
	cin >> num1 >> num2;

	int a = 100 - num1, b = 100 - num2;
	int c = 100 - (a + b), d = a * b;
	int q = d / 100, r = d % 100;

	cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << q << ' ' << r << '\n';

	cout << num1 * num2 / 100 << ' ' << num1 * num2  % 100 << '\n';

	return 0;
}