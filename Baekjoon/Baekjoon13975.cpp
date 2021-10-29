// Baekjoon13975.cpp
// https://www.acmicpc.net/problem/13975
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;

			pq.push(temp);
		}

		ll ans = 0LL;
		while (pq.size() > 1) {
			ll val1 = pq.top(); pq.pop();
			ll val2 = pq.top(); pq.pop();

			pq.push(val1 + val2);
			ans += val1 + val2;
		}

		cout << ans << '\n';
	}

	return 0;
}