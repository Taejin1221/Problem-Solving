// Codeforces_.cpp
#include <iostream>

#include <vector>

#define MOD 1'000'000'007

using namespace std;

long long power(int n, int k) {
	if (k == 0)
		return 1;
	else if (k == 1)
		return n;
	else {
		long long half = power(n, k / 2);

		long long result = (half * half) % MOD;
		if (k % 2)
			result = (result * n) % MOD;

		return result;
	}
}

void solveTestCase() {
	int n, k;
	cin >> n >> k;

	vector<bool> binary;
	while (k > 0) {
		binary.push_back(k % 2);
		k /= 2;
	}

	long long ans = 0;
	for (int i = 0; i < binary.size(); i++) {
		if (binary[i])
			ans = (ans + power(n, i)) % MOD;
	}

	cout << ans << '\n';
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
