// Baekjoon02903.cpp
// https://www.acmicpc.net/problem/2903
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int base = 3;
	for (int i = 1; i < n; i++)
		base += (1 << i);

	cout << base * base << '\n';

	return 0;
}