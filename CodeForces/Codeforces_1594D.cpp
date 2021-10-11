// Codeforces_1594D.cpp
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

#define IMPOSTER -1
#define CREWMATE 1

using namespace std;

struct Node {
	int vertex, weight;
	Node(): vertex(0), weight(0) { }
	Node(int v, int w): vertex(v), weight(w) { }
};

int team[200'001];
vector<int> visitedList;
vector<Node> adjList[200'001];

bool dfs(int curr) {
	for (Node& adj : adjList[curr]) {
		if (team[adj.vertex] == 0) {
			team[adj.vertex] = team[curr] * adj.weight;
			visitedList.push_back(adj.vertex);
			if (dfs(adj.vertex))
				return true;
		} else {
			if (team[curr] * adj.weight != team[adj.vertex])
				return true;
		}
	}

	return false;
}

void solveTestCase() {
	int n, m;
	cin >> n >> m;

	fill(team, team + n + 1, 0);
	for (int i = 1; i <= n; i++)
		adjList[i].clear();

	for (int i = 0; i < m; i++) {
		int start, end; string job;
		cin >> start >> end >> job;

		int weight = (job == "imposter") ? IMPOSTER : CREWMATE;
		adjList[start].push_back(Node(end, weight));
		adjList[end].push_back(Node(start, weight));
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) {
			team[i] = IMPOSTER;
			visitedList.push_back(i);
			bool isContradict = dfs(i);

			int result1 = 0;
			for (int j = 0; j < visitedList.size(); j++) {
				if (team[visitedList[j]] == IMPOSTER)
					result1++;
				team[visitedList[j]] = 0;
			}
			if (isContradict)
				result1 = 0;
			visitedList.clear();

			team[i] = CREWMATE;
			visitedList.push_back(i);
			isContradict &= dfs(i);

			int result2 = 0;
			for (int j = 0; j < visitedList.size(); j++) {
				if (team[visitedList[j]] == IMPOSTER)
					result2++;
			}
			if (isContradict)
				result2 = 0;
			visitedList.clear();

			if (isContradict) {
				cout << -1 << '\n';
				return;
			} else
				ans += max(result1, result2);
		}
	}

	cout << ans << '\n';
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
