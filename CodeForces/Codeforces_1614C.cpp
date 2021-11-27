// Codeforces_1614C.cpp
#include <iostream>

#define MOD 1'000'000'007

using namespace std;

using ll = long long;

ll pow2(int y) {
	if (y == 0)
		return 1LL;
	else {
		ll half = pow2(y / 2);
		ll result = half * half % MOD;
		if (y % 2)
			result = result * 2 % MOD;
		return result;
	}
}

void solveTestCase() {
	int n, m;
	cin >> n >> m;

	ll value = 0;
	for (int i = 0; i < m; i++) {
		ll x, _;
		cin >> _ >> _ >> x;
		value |= x;
	}

	ll power2 = pow2(n - 1);
	cout << (value * power2 % MOD) << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}