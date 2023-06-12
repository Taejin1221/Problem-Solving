// Baekjoon23829.cpp
// https://www.acmicpc.net/problem/23829
#include <iostream>

#include <algorithm>

using namespace std;

using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	ll n, t;
	cin >> n >> t;

	ll sum = 0LL;

	int tree[100'001] = { 0, };
	ll prefixSum[100'001] = { 0LL, };
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
		sum += tree[i];
	}
	sort(tree + 1, tree + n + 1);

	for (int i = 1; i <= n; i++)
		prefixSum[i] = prefixSum[i - 1] + (n - 2 * (i - 1)) * (tree[i] - tree[i - 1]);

	while (t--) {
		ll q;
		cin >> q;

		int idx = lower_bound(tree, tree + n + 1, q) - tree;
		if (n < idx)
			idx = n;
		else
			if (q != tree[idx])
				idx--;

		cout << (sum - prefixSum[idx] - (n - 2 * idx) * (q - tree[idx])) << '\n';
	}
}