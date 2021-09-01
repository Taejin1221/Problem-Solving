// Baekjoon13172.cpp
// https://www.acmicpc.net/problem/13172
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

typedef long long ll;

ll myPow(ll x, ll y) {
	if (y == 0)
		return 1;

	ll result = myPow(x, y / 2);
	result = result * result % MOD;
	if (y % 2)
		result = result * x % MOD;
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	ll ans = 0;
	while (n--) {
		ll a, b;
		cin >> b >> a;

		ll result = a * myPow(b, MOD - 2) % MOD;
		ans = (ans + result) % MOD;
	}

	cout << ans << '\n';

	return 0;
}