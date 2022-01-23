// Baekjoon21612.cpp
// https://www.acmicpc.net/problem/21612
#include <iostream>

using namespace std;

int main(void) {
	int a;
	cin >> a;

	cout << a * 5 - 400 << '\n';
	if (a < 100)
		cout << 1;
	else if (a == 100)
		cout << 0;
	else
		cout << -1;
	cout << '\n';

	return 0;
}