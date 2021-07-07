// Baekjoon10156_Snack.cpp
// https://www.acmicpc.net/problem/10156
#include <iostream>

using namespace std;

int main(void) {
	int k, n, m;
	cin >> k >> n >> m;

	int total = k * n;
	int ans = ( total > m ) ? total - m : 0;

	cout << ans << '\n';

	return 0;
}