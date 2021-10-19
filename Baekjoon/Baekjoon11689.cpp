// Baekjoon11689.cpp
// https://www.acmicpc.net/problem/11689
#include <iostream>

#include <vector>

using namespace std;

typedef long long ll;

vector<ll> factors;
vector<ll> products;

void getProducts(int idx, ll currProduct, int currSize, int targetSize) {
	if (factors.size() < idx)
		return;

	if (currSize == targetSize) {
		products.push_back(currProduct);
	}
	else {
		getProducts(idx + 1, currProduct * factors[idx], currSize + 1, targetSize);
		getProducts(idx + 1, currProduct, currSize, targetSize);
	}
}

int main(void) {
	ll n;
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';

		return 0;
	}

	bool isPrime[1'000'001] = { false, };
	fill(isPrime + 2, isPrime + 1'000'001, true);

	vector<ll> primeNumbers;
	for (ll i = 2; i <= 4 || i * i <= n; i++) {
		if (isPrime[i]) {
			primeNumbers.push_back(i);
			for (ll j = i * i; j <= 1'000'000 && j * j <= n; j += i)
				isPrime[j] = false;
		}
	}

	ll tempN = n;
	for (int i = 0; i < primeNumbers.size(); i++) {
		if (tempN % primeNumbers[i] == 0) {
			while (tempN % primeNumbers[i] == 0)
				tempN /= primeNumbers[i];
			factors.push_back(primeNumbers[i]);
		}
	}

	if (tempN > primeNumbers.back())
		factors.push_back(tempN);

	ll ans = n, sign = -1;
	for (int i = 1; i <= factors.size(); i++) {
		products.clear();
		getProducts(0, 1, 0, i);
		for (int j = 0; j < products.size(); j++)
			ans += sign * (n / products[j]);
		sign *= -1;
	}

	cout << ans << '\n';

	return 0;
}