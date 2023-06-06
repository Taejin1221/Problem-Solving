// Baekjoon13909.cpp
// https://www.acmicpc.net/problem/13909
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int ans;
	for (ans = 1; ans * ans <= n; ans++);

	cout << ans - 1 << '\n';

	return 0;
}