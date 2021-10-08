// Baekjoon23086.cpp
// https://www.acmicpc.net/problem/23086
#include <iostream>

#include <vector>
#include <algorithm>

#define NODE_SIZE 100'001
#define LIST_SIZE 200'001

using namespace std;

struct Node {
	int adj, num;
	Node(): adj(0), num(0) { }
	Node(int a, int n): adj(a), num(n) { }
};

int team[NODE_SIZE];
bool isConnected[LIST_SIZE];
vector<Node> adjList[NODE_SIZE];

bool canBipartite(int start, int myTeam) {
	for (Node& adj : adjList[start]) {
		if (isConnected[adj.num]) {
			if (team[adj.adj] == myTeam)
				return false;
			else if (team[adj.adj] == 0) {
				team[adj.adj] = -myTeam;
				if (!canBipartite(adj.adj, -myTeam))
					return false;
			}
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(Node(b, i));
		adjList[b].push_back(Node(a, i));
	}

	int list[LIST_SIZE] = { 0, };
	for (int i = 1; i <= k; i++)
		cin >> list[i];

	int left = 0, right = k;
	while (left <= right) {
		int mid = (left + right) / 2;

		fill(isConnected + 1, isConnected + m + 1, true);
		for (int i = 1; i <= mid; i++)
			isConnected[list[i]] = false;

		fill(team + 1, team + n + 1, 0);
		if (canBipartite(1, 1))
			right = mid - 1;
		else
			left = mid + 1;
	}

	int ans = right + 1;
	if (k < ans)
		cout << -1;
	else {
		cout << ans << '\n';

		fill(isConnected + 1, isConnected + m + 1, true);
		for (int i = 1; i <= ans; i++)
			isConnected[list[i]] = false;

		fill(team + 1, team + n + 1, 0);
		canBipartite(1, 1);

		int team1, team2;
		for (int i = 1; i <= n; i++)
			(team[i] == 1) ? team1++ : team2++;

		if (team1 < team2)
			cout << team1 << ' ' << team2;
		else
			cout << team2 << ' ' << team1;
	}
	cout << '\n';

	return 0;
}