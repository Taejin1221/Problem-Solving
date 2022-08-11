// Baekjoon23375.cpp
// https://www.acmicpc.net/problem/23375
#include <iostream>

using namespace std;

int main(void) {
	int x1, y1, r;
	cin >> x1 >> y1 >> r;

	cout << x1 - r << ' ' << y1 + r << endl;
	cout << x1 + r << ' ' << y1 + r << endl;
	cout << x1 + r << ' ' << y1 - r << endl;
	cout << x1 - r << ' ' << y1 - r << endl;

	return 0;
}