// Baekjoon06502.cpp
// https://www.acmicpc.net/problem/6502
#include <iostream>

#define SQUARE(x) (x) * (x)

using namespace std;

int main(void) {
	int r, w, l;
	cin >> r;

	int t = 1;
	while (r != 0) {
		cin >> w >> l;

		int r2 = r * 2;
		cout << "Pizza " << t;
		if (SQUARE(r2) >= SQUARE(w) + SQUARE(l))
			cout << " fits on the table.";
		else
			cout << " does not fit on the table.";
		cout << '\n';

		cin >> r;
		t++;
	}

	return 0;
}