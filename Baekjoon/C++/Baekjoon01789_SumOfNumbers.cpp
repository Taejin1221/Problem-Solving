// Baekjoon01789_SumOfNumbers.cpp
// https://www.acmicpc.net/problem/1789
#include <iostream>

using namespace std;

int main(void) {
	long long n;
	cin >> n;

	int ans = 1, prev = 1;
	for (long long i = 1; i <= 100'000; i++) {
		long long sum = i * (i + 1) / 2;
		if (sum > n) {
			ans = prev;
			break;
		}
		else
			prev = i;
	}

	cout << prev << '\n';

	return 0;
}