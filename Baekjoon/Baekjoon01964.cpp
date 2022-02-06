// Baekjoon01964.cpp
// https://www.acmicpc.net/problem/1964
#include <iostream>

#define MOD 45678

using namespace std;

using ll = long long;

int main(void) {
	int n;
	cin >> n;

	ll curr = 5, prev = 5;
	for (int i = 2; i <= n; i++) {
		curr = prev + (i + 1) * 2 + (i + 1) - 2;
		curr %= MOD;

		prev = curr;
	}

	cout << curr << '\n';

	return 0;
}