// Baekjoon23827.cpp
// https://www.acmicpc.net/problem/23827
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const ll mod = 1'000'000'007LL;

	int n;
	cin >> n;

	int arr[500'000];
	ll prefixSum[500'001] = { 0LL, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		prefixSum[i + 1] = prefixSum[i] + arr[i];
	}

	ll ans = 0LL;
	for (int i = 1; i < n; i++) {
		ans += arr[i] * prefixSum[i];
		ans %= mod;
	}

	cout << ans << '\n';

	return 0;
}