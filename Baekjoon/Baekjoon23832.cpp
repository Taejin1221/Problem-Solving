// Baekjoon23832.cpp
// https://www.acmicpc.net/problem/23832
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<int> prime;

ll getCoprime(int num) {
	pair<ll, ll> ans = { 1LL, 1LL };
	for (int i = 0; i < prime.size() && prime[i] <= num; i++) {
		if (num % prime[i] == 0) {
			ans.first *= prime[i] - 1;
			ans.second *= prime[i];
		}
	}

	return num * ans.first / ans.second;
}

int main(void) {
	int n;
	cin >> n;

	bool sieve[50'001];
	fill(sieve + 2, sieve + 50'001, true);

	for (int i = 2; i <= n; i++) {
		if (sieve[i]) {
			prime.push_back(i);
			for (ll j = (ll)i * i; j <= n; j += i)
				sieve[j] = false;
		}
	}

	ll ans = 0LL;
	for (int i = 2; i <= n; i++)
		ans += getCoprime(i);

	cout << ans << '\n';

	return 0;
}