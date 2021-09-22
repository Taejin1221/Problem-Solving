// Baekjoon20171.cpp
// https://www.acmicpc.net/problem/20171
#include <iostream>

#include <vector>

#define MAX 100'001

using namespace std;

bool isApart[MAX];
int hasApartSub[MAX];
vector<int> adjList[MAX];

int dfs(int me, int mom) {
	for (int& adj : adjList[me]) {
		if (adj != mom)
			if (dfs(adj, me))
				hasApartSub[me]++;
	}

	return isApart[me] ? 1 : hasApartSub[me];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	int minApart = MAX;
	for (int i = 0; i < k; i++) {
		int apart;
		cin >> apart;

		isApart[apart] = true;
		minApart = min(minApart, apart);
	}

	dfs(minApart, -1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (isApart[i] || hasApartSub[i] >= 1)
			ans++;

	cout << ans << '\n';

	return 0;
}