// Baekjoon02513.cpp
// https://www.acmicpc.net/problem/2513
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, s;
	cin >> n >> k >> s;

	int ans = 0;
	vector<pii> aparts[2]; // leftApart, rightApart, { position, students }
	for (int i = 0; i < n; i++) {
		pii apart;
		cin >> apart.first >> apart.second;

		int isLeft = apart.first >= s;

		apart.first = abs(s - apart.first);
		ans += apart.second / k * apart.first;
		apart.second %= k;
		if (apart.second)
			aparts[isLeft].push_back(apart);
	}

	for(int i = 0; i < 2; i++) {
		if (aparts[i].size() == 0)
			continue;

		sort(aparts[i].begin(), aparts[i].end(), greater<pii>());

		// { distance, students };
		pii curr = aparts[i][0];
		int size = aparts[i].size();
		for (int j = 1; j < size; j++) {
			pii currApart = aparts[i][j];
			curr.second += currApart.second;
			if (curr.second > k) {
				ans += curr.first;
				curr = { currApart.first, curr.second - k };
			} else if (curr.second == k) {
				ans += curr.first;
				if (j < size - 1)
					curr = { aparts[i][j + 1].first, 0 };
				else
					curr.second = 0;
			}
		}
		if (curr.second)
			ans += curr.first;
	}

	cout << ans * 2 << '\n';

	return 0;
}