// Baekjoon09466.cpp
// https://www.acmicpc.net/problem/9466
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int parent[100'001];

int findRoot(int a) {
	return parent[a] = (parent[a] != a) ? findRoot(parent[a]) : a;
}

void unionTwoTree(int aRoot, int bRoot) {
	if (aRoot > bRoot)
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}



void solve() {
	int n;
	cin >> n;

	int choose[100'001];
	for (int i = 1; i <= n; i++) {
		cin >> choose[i];
		parent[i] = i;
	}

	vector<int> cycleNodes;
	for (int i = 1; i <= n; i++) {
		int aRoot = findRoot(i), bRoot = findRoot(choose[i]);
		if (aRoot == bRoot) {
			cycleNodes.push_back(i);
		} else {
			unionTwoTree(aRoot, bRoot);
		}
	}

	int ans = n;
	for (int& currCycle : cycleNodes) {

		vector<int> stck;
		int target = currCycle;

		function<void(int)> dfs = [&, target](int curr) {
		if (choose[curr] != target) {
			stck.push_back(choose[curr]);
			dfs(choose[curr]);
		} else
			return;
		};

		stck.push_back(currCycle);
		dfs(currCycle);

		ans -= stck.size();
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}