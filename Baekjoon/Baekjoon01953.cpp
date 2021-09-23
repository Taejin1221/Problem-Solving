// Baekjoon01953.cpp
// https://www.acmicpc.net/problem/1953
#include <iostream>

#include <vector>

using namespace std;

int team[101], teamA;
vector<int> adjList[101];

void dfs(int curr, int prevTeam) {
	for (int& adj : adjList[curr]) {
		if (!team[adj]) {
			if (prevTeam == -1)
				teamA++;

			team[adj] = -prevTeam;
			dfs(adj, -prevTeam);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		while (t--) {
			int a; cin >> a;

			adjList[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!team[i]) {
			teamA++;
			team[i] = 1;
			dfs(i, 1);
		}
	}

	cout << teamA << '\n';
	for (int i = 1; i <= n; i++)
		if (team[i] == 1)
			cout << i << ' ';
	cout << '\n';

	cout << n - teamA << '\n';
	for (int i = 1; i <= n; i++)
		if (team[i] == -1)
			cout << i << ' ';
	cout << '\n';
}