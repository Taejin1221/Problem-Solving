// Baekjoon24313.cpp
// https://www.acmicpc.net/problem/24313
#include <iostream>

using namespace std;

int main(void) {
	int a1, a0, c, n0;
	cin >> a1 >> a0 >> c >> n0;

	bool isSatisfy = true;

	for (int n = n0; n <= 10'000; n++) {
		if (a1 * n + a0 > c * n) {
			isSatisfy = false;
			break;
		}
	}

	if (isSatisfy)
		cout << 1;
	else
		cout << 0;
	cout << '\n';

	return 0;
}