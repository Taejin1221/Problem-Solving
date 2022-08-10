// Baekjoon01392.cpp
// https://www.acmicpc.net/problem/1392
#include <iostream>

using namespace std;

int main(void) {
	int n, q;
	cin >> n >> q;

	int second[10'000] = { 0, };
	for (int i = 1, j = 0; i <= n; i++) {
		int curr;
		cin >> curr;

		for (int k = 0; k < curr; k++)
			second[j++] = i;
	}

	while (q--) {
		int query;
		cin >> query;

		cout << second[query] << '\n';
	}

	return 0;
}