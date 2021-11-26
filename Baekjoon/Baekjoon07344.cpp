// Baekjoon07344.cpp
// https://www.acmicpc.net/problem/7344
#include <iostream>

#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		pii sticks[5'000];
		for (int i = 0; i < n; i++)
			cin >> sticks[i].first >> sticks[i].second;

		sort(sticks, sticks + n);

		int ans = 0, selectNum = n;
		bool isSelected[5'000] = { false, };
		while (selectNum) {
			pii prev = { 0, 0 };
			for (int i = 0; i < n; i++) {
				if (!isSelected[i] && (prev.first <= sticks[i].first && prev.second <= sticks[i].second)) {
					prev = sticks[i];
					selectNum--;
					isSelected[i] = true;
				}
			}
			ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}