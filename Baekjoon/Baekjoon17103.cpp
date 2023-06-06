// Baekjoon17103.cpp
// https://www.acmicpc.net/problem/17103
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<bool> isPrime(1'000'001, true);
	isPrime[1] = false;

	for (int i = 2; i <= 1'000; i++)
		if (isPrime[i])
			for (int j = i * i; j <= 1'000'000; j += i)
				isPrime[j] = false;

	vector<int> primes;
	for (int i = 2; i <= 1'000'000; i++)
		if(isPrime[i])
			primes.push_back(i);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++)
			if (isPrime[n - primes[i]])
				ans++;

		cout << ans << '\n';
	}

	return 0;
}