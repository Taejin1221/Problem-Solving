// Baekjoon13241.cpp
// https://www.acmicpc.net/problem/13241
#include <iostream>

using namespace std;

using ll = long long;

ll GCD(ll a, ll b) {
	return (a % b) ? GCD(b, a % b) : b;
}

int main(void) {
	ll a, b;
	cin >> a >> b;

	ll gcd = (a > b) ? GCD(a, b) : GCD(b, a);

	cout << a * b / gcd << '\n';

	return 0;
}