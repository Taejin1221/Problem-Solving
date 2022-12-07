// Baekjoon17162.cpp
// https://www.acmicpc.net/problem/17162
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, k;
	cin >> t >> k;

	vector<int> table[100];

	vector<int> stck;
	while (t--) {
		int q;
		cin >> q;

		if (q == 1) {
			int n;
			cin >> n;

			stck.push_back(n % k);
			table[n % k].push_back(stck.size() - 1);
		} else if (q == 2) {
			if (!stck.empty()) {
				int last = stck.back();
				table[last].pop_back();
				stck.pop_back();
			}
		} else {
			int minIdx = stck.size();
			bool isPossible = true;
			for (int i = 0; i < k; i++) {
				if (table[i].size() == 0) {
					isPossible = false;
					break;
				}

				minIdx = min(minIdx, table[i].back());
			}

			if (isPossible)
				cout << stck.size() - minIdx;
			else
				cout << -1;
			cout << '\n';
		}
	}

	return 0;
}