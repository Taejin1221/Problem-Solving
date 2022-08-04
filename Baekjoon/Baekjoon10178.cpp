// Baekjoon10178.cpp
// https://www.acmicpc.net/problem/10178
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	while (n--) {
		int c, v;
		cin >> c >> v;

		cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
	}

	return 0;
}