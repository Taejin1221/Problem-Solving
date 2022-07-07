// Baekjoon03578.cpp
// https://www.acmicpc.net/problem/3578
#include <iostream>

using namespace std;

int main(void) {
	int h;
	cin >> h;

	if (h == 0)
		cout << 1;
	else if (h == 1)
		cout << 0;
	else if (h == 2)
		cout << 8;
	else {
		if (h % 2) {
			cout << 4;
			h--;
		}
		for (int i = 0; i < h / 2; i++)
			cout << 8;
	}

	cout << '\n';

	return 0;
}
