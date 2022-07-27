// Baekjoon05073.cpp
// https://www.acmicpc.net/problem/5073
#include <iostream>

using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;

	while (a != 0 && b != 0 && c != 0) {
		int sum = a + b + c;
		int maxVal = max(a, max(b, c));

		if (maxVal >= sum - maxVal)
			cout << "Invalid";
		else if (a == b && b == c)
			cout << "Equilateral";
		else if (a != b && b != c && c != a)
			cout << "Scalene";
		else
			cout << "Isosceles";
		cout << '\n';

		cin >> a >> b >> c;
	}

	return 0;
}