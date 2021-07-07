// Baekjoon10162_Microwave.cpp
// https://www.acmicpc.net/problem/10162
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	int a = 300, b = 60, c = 10;

	if ( t % 10 )
		cout << -1;
	else {
		cout << t / a << ' ';
		t %= a;

		cout << t / b << ' ';
		t %= b;

		cout << t / c;
	}
	cout << '\n';

	return 0;
}