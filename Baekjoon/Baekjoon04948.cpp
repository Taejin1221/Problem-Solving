// BOJ_04948.cpp
#include <iostream>

#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool isPrime[300'000];
	fill(isPrime, isPrime + 300'000, true);
	isPrime[0] = isPrime[1] = false;

	for (ll i = 2; i <= (ll)123'456 * 2; i++) {
		if (isPrime[i]) {
			for (ll j = i * i; j < 300'000; j += i)
				isPrime[j] = false;
		}
	}

	int primeSum[300'000] = { 0, };
	for (int i = 1; i <= 123'456 * 2; i++) {
		primeSum[i + 1] = (isPrime[i] ? 1 : 0) + primeSum[i];
	}

	int n;
	cin >> n;
	while (n != 0) {
		cout << primeSum[n * 2 + 1] - primeSum[n + 1] << '\n';

		cin >> n;
	}

	return 0;
}