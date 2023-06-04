// Baekjoon24267.cpp
// https://www.acmicpc.net/problem/24267
#include <iostream>

using namespace std;

int main(void) {
	long long n;
	cin >> n;

	long long son = (n - 2) * (n - 1) * (2 * n - 3) + 3 * (n - 2) * (n - 1);
	cout << son / 12 << '\n';
	cout << 3 << '\n';

	return 0;
}