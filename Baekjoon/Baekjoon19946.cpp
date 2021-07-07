// Baekjoon19946_CalculatePowerOf2.cpp
// https://www.acmicpc.net/problem/19946
#include <iostream>
#include <climits>

using namespace std;

typedef unsigned long long ull;

int main(void) {
	ull n;
	cin >> n;

	ull diff = ULLONG_MAX - n + 1;

	int ans;

	diff = diff >> 1;
	for ( ans = 0; diff; ans++ )
		diff = diff >> 1;

	cout << 64 - ans << '\n';

	return 0;
}