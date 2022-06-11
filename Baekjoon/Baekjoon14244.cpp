// Baekjoon14244.cpp
// https://www.acmicpc.net/problem/14244
#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n - m; i++)
		cout << i - 1 << ' ' << i << '\n';

	cout << n - m - 1 << ' ' << n - m << '\n';
	for (int i = n - m + 1; i < n; i++)
		cout << 0 << ' ' << i << '\n';

	return 0;
}