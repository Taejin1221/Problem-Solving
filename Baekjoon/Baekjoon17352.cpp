// Baekjoon17352.cpp
// https://www.acmicpc.net/problem/17352
#include <iostream>

#include <vector>

#define SIZE 300'001

using namespace std;

int team[SIZE];
vector<int> adjList[SIZE];

void dfs(int me, int mom, int myTeam) {
	for (int& adj : adjList[me]) {
		if (adj != mom) {
			team[adj] = myTeam;
			dfs(adj, me, myTeam);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	int myTeam = 1;
	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) {
			team[i] = myTeam;
			dfs(i, 0, myTeam);
			myTeam++;
		}
	}

	int firstTeam2 = 0;
	for (int i = 1; i <= n; i++) {
		if (team[i] == 2) {
			firstTeam2 = i;
			break;
		}
	}

	cout << 1 << ' ' << firstTeam2 << '\n';

	return 0;
}