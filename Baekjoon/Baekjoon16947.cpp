// Baekjoon16947.cpp
// https://www.acmicpc.net/problem/16947
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> stck, adjList[3'001];
bool visited[3'001], isInStck[3'001], isCycle[3'001];

void dfs(int start, int from);
int getMinDistanceToCyle(int start);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
		cout << getMinDistanceToCyle(i) << ' ';
	cout << '\n';

	return 0;
}

void dfs(int start, int from) {
	visited[start] = true;
	isInStck[start] = true;
	stck.push_back(start);

	for (int& adj : adjList[start]) {
		if (adj == from)
			continue;

		if (!visited[adj])
			dfs(adj, start);
		else if (isInStck[adj]) {
			int top = stck.back();
			while (top != adj) {
				isCycle[top] = true;
				isInStck[top] = false;
				stck.pop_back();

				top = stck.back();
			}

			isCycle[top] = true;
			isInStck[top] = false;
			stck.pop_back();
		}
	}

	if (isInStck[start]) {
		stck.pop_back();
		isInStck[start] = false;
	}
}

int getMinDistanceToCyle(int start) {
	queue<pii> q;

	q.push({ start, 0 });
	fill(visited + 1, visited + 3'001, false);
	visited[start] = true;

	int ans = -1;
	while (!q.empty()) {
		pii curr = q.front(); q.pop();

		if (isCycle[curr.first]) {
			ans = curr.second;
			break;
		}

		for (int& adj : adjList[curr.first]) {
			if (!visited[adj]) {
				visited[adj] = true;
				q.push({ adj, curr.second + 1 });
			}
		}
	}

	return ans;
}