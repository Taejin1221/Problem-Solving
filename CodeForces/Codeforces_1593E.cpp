// Codeforces_1593E.cpp
#include <iostream>

#include <queue>
#include <vector>

#define SIZE 400'001

using namespace std;

void solveTestCase( ) {
	int n, k;
	cin >> n >> k;

	int ans = n;

	vector<vector<int>> adjList(n + 1, vector<int>());
	vector<int> degree(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);

		degree[u]++, degree[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 1) {
			degree[i]--;
			q.push(i);
		}
	}

	while (k && ans) {
		if (ans <= 2)
			ans = 0;
		else {
			int prevLeafSize = q.size();
			for (int i = 0; i < prevLeafSize; i++) {
				int curr = q.front(); q.pop();
				for (int& adj : adjList[curr])
					if (--degree[adj] == 1)
						q.push(adj);

				ans--;
			}
		}

		k--;
	}

	cout << ans << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solveTestCase( );
	}

	return 0;
}
