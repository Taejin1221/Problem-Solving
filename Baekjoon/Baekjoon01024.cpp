// Baekjoon1024_SumOfSequence.cpp
// https://www.acmicpc.net/problem/1024
#include <iostream>

using namespace std;

int main(void) {
	int n, startL;
	cin >> n >> startL;

	int start, l;
	for (l = startL; l <= 100; l++) {
		if (l == 2) {
			if (n % 2) {
				start = n / 2;
				break;
			}
		} else if ((l % 2 == 1) && (n % l == 0)) {
			start = n / l - l / 2;
			if (start >= 0)
				break;
		} else if ((l % 2 == 0) && (n % (l / 2) == 0) && ((n / (l / 2)) % 2 == 1)) {
			start = n / l - (l / 2 - 1);
			if (start >= 0)
				break;
		}
	}

	if (l > 100)
		cout << -1;
	else
		for (int i = start; i < start + l; i++)
			cout << i << ' ';
	cout << '\n';

	return 0;
}