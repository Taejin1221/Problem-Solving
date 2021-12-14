// Baekjoon23835.cpp
// https://www.acmicpc.net/problem/23835
#include <iostream>

#include <vector>
#include <algorithm>

#define SIZE 1'001

using namespace std;

vector<int> milk(SIZE), stck;
vector<int> adjList[SIZE];

bool dfs(int me, int mom, int target) {
	stck.push_back(me);
	if (me == target)
		return true;

	for (int& son : adjList[me]) {
		if (son != mom)
			if (dfs(son, me, target))
				return true;
	}

	stck.pop_back();
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int m;
	cin >> m;
	while (m--) {
		int q;
		cin >> q;

		if (q == 1) {
			int u, v;
			cin >> u >> v;

			dfs(u, -1, v);

			for (int i = 0; i < stck.size(); i++)
				milk[stck[i]] += i;
			stck.clear();
		} else {
			int u;
			cin >> u;

			cout << milk[u] << '\n';
		}
	}

	return 0;
}