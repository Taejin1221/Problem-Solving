// Baekjoon10807.cpp
// https://www.acmicpc.net/problem/10807
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int table[201] = { 0, };
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		table[a + 100]++;
	}

	int v;
	cin >> v;

	cout << table[v + 100] << '\n';

	return 0;
}