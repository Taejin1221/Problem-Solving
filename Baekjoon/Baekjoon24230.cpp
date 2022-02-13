// Baekjoon24230.cpp
// https://www.acmicpc.net/problem/24230
#include <iostream>

#include <vector>

#define MAX 200'001

using namespace std;

int ans, target[MAX];
vector<int> adjList[MAX];

void dfs(int me, int mom, int color) {
	for (int& son : adjList[me]) {
		if (son != mom) {
			if (target[son] != color)
				ans++;
			dfs(son, me, target[son]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> target[i];

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	ans = (target[1] != 0);
	dfs(1, 0, target[1]);

	cout << ans << '\n';

	return 0;
}