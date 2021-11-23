// Baekjoon03058.cpp
// https://www.acmicpc.net/problem/3058
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int minValue = 101, sum = 0;
		for (int i = 0; i < 7; i++) {
			int temp2;
			cin >> temp2;
			if (temp2 % 2 == 0) {
				sum += temp2;
				minValue = min(minValue, temp2);
			}
		}

		cout << sum << ' ' << minValue << '\n';
	}

	return 0;
}