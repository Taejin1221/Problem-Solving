// Baekjoon17503.cpp
// https://www.acmicpc.net/problem/17503
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Compare {
	bool operator()(pii a, pii b) {
		return a.second < b.second;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	pii beers[200'000];
	for (int i = 0; i < k; i++)
		cin >> beers[i].first >> beers[i].second;
	sort(beers, beers + k);

	ll vSum = 0LL;
	priority_queue<pii, vector<pii>, Compare> pq;
	for (int i = 0; i < n; i++) {
		vSum += (ll)beers[k - 1 - i].first;
		pq.push(beers[k - 1 - i]);
	}

	if (vSum < m)
		cout << -1;
	else {
		int minDegree = pq.top().second;
		for (int i = k - n - 1; i >= 0; i--) {
			ll diff = pq.top().first - beers[i].first;

			pq.pop();
			pq.push(beers[i]);

			vSum -= diff;
			if (vSum >= m)
				minDegree = min(minDegree, pq.top().second);
		}

		cout << minDegree;
	}
	cout << '\n';

	return 0;
}