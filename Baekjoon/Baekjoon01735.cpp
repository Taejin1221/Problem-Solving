// Baekjoon01735.cpp
// https://www.acmicpc.net/problem/1735
#include <iostream>

using namespace std;

int getGCD(int a, int b) {
	return (a % b == 0) ? b : getGCD(b, a % b);
}

int main(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int son = a * d + c * b, mom = b * d;
	int gcd = (son > mom) ? getGCD(son, mom) : getGCD(mom, son);

	cout << son / gcd << ' ' << mom / gcd << '\n';

	return 0;
}