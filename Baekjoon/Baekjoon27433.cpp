// Baekjoon27433.cpp
// https://www.acmicpc.net/problem/27433
#include <iostream>

using namespace std;

using ll = long long;

ll fac(ll n) {
	if (n == 0)
		return 1;
	else
		return n * fac(n - 1);
}

int main(void) {
	ll n;
	cin >> n;

	cout << fac(n) << '\n';

	return 0;
}