// Codeforces_1602B.cpp
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int queryNum, idx, k;
	Node(): queryNum(0), idx(0), k(0) { }
	bool operator<(const Node& n2) const {
		return k < n2.k;
	}
};

void solveTestCase() {
	int n;
	cin >> n;

	vector<int> arr(n), count(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		count[arr[i]]++;
	}

	int q;
	cin >> q;
	vector<Node> queries(q);
	for (int i = 0; i < q; i++) {
		queries[i].queryNum = i;
		cin >> queries[i].idx >> queries[i].k;
	}

	sort(queries.begin(), queries.end());

	int prevK = 0; bool isConvergence = false;
	vector<int> ans(q);
	for (int i = 0; i < q; i++) {
		if (!isConvergence) {
			while (prevK < queries[i].k) {
				vector<int> newCount(n + 1);
				for (int idx = 0; idx < n; idx++) {
					arr[idx] = count[arr[idx]];
					newCount[arr[idx]]++;
				}
				count = newCount;
				prevK++;

				isConvergence = true;
				for (int idx = 1; idx <= n; idx++)
					isConvergence &= (count[idx] == 0 || idx == count[idx]);

				if (isConvergence)
					break;
			}
		}

		ans[queries[i].queryNum] = arr[queries[i].idx - 1];
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase();
	}

	return 0;
}
