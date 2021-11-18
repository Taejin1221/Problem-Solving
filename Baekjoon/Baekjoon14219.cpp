// Baekjoon14219.cpp
// https://www.acmicpc.net/problem/14219
#include <iostream>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;

	cout << ((n % 3 == 0 || m % 3 == 0) ? "YES" : "NO") << '\n';

	return 0;
}