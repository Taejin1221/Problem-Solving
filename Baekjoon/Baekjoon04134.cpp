// Baekjoon04134.cpp
// https://www.acmicpc.net/problem/4134
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<bool> isPrime(1'000'001, true);
	isPrime[1] = false;

	vector<ll> primes;
	for (ll i = 2; i <= 1'000; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (ll j = i * i; j <= 1'000'000; j += i) {
				isPrime[j] = false;
			}
		}
	}
	for (int i = 1'000; i <= 1'000'000; i++)
		if (isPrime[i])
			primes.push_back(i);

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		if (n == 0 || n == 1) {
			cout << 2 << '\n';
		} else {
			ll ans = n;
			bool isPrime = false;
			while (!isPrime) {
				isPrime = true;
				for (int i = 0; i < primes.size() && primes[i] * primes[i] <= ans; i++) {
					if (ans % primes[i] == 0) {
						isPrime = false;
						break;
					}
				}
				if (!isPrime)
					ans++;
			}

			cout << ans << '\n';
		}

	}

	return 0;
}