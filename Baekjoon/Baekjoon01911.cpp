// Baekjoon01911.cpp
// https://www.acmicpc.net/problem/1911
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	pii puddle[10'000];
	for (int i = 0; i < n; i++)
		cin >> puddle[i].first >> puddle[i].second;

	sort(puddle, puddle + n);

	int prevEnd = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (puddle[i].second <= prevEnd)
			continue;

		int numPud = puddle[i].second - max(prevEnd, puddle[i].first);
		int numWood = numPud / l + (numPud % l != 0);
		ans += numWood;

		prevEnd = max(prevEnd, puddle[i].first) + numWood * l;
	}

	cout << ans << '\n';

	return 0;
}