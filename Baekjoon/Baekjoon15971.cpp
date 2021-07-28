// Baekjoon15971.cpp
// https://www.acmicpc.net/problem/15971
#include <iostream>

#include <queue>

using namespace std;

struct Node {
	int vertex, weight;
	Node(int v, int w): vertex(v), weight(w) { }
};

int target;
bool visited[100'001];
vector<int> path;
vector<Node> adjList[100'001];

bool dfs(int curr);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, start;
	cin >> n >> start >> target;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back(Node(b, c));
		adjList[b].push_back(Node(a, c));
	}

	visited[start] = true;
	dfs(start);

	int sum = 0, maxValue = 0;
	for (int i = 0; i < path.size(); i++) {
		sum += path[i];
		maxValue = max(maxValue, path[i]);
	}

	cout << sum - maxValue << '\n';

	return 0;
}

bool dfs(int curr) {
	if (curr == target)
		return true;
	else {
		for (Node& adj : adjList[curr]) {
			if (!visited[adj.vertex]) {
				visited[adj.vertex] = true;
				path.push_back(adj.weight);
				if (dfs(adj.vertex))
					return true;
				path.pop_back();
			}
		}
	}	

	return false;
}