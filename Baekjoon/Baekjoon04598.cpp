// Baekjoon04598.cpp
// https://www.acmicpc.net/problem/4589
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	cout << "Gnomes:\n";
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;

		if ((a < b && b < c) || (a > b && b > c))
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}

	return 0;
}