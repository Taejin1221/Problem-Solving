// Baekjoon04196.cpp
// https://www.acmicpc.net/problem/4196
#include <iostream>

#include <vector>
#include <algorithm>

#define MAX_NODE 100'001

using namespace std;

bool visited[MAX_NODE], indegree[MAX_NODE];
int number[MAX_NODE], numIdx, sccGroup[MAX_NODE], sccIdx;
vector<int> adjList[MAX_NODE], reverseAdjList[MAX_NODE];

void checkNumber(int start) {
	visited[start] = true;
	for (int& adj : adjList[start])
		if (!visited[adj])
			checkNumber(adj);
	number[numIdx++] = start;
}

void groupSCC(int start) {
	visited[start] = true;
	sccGroup[start] = sccIdx;
	for (int& adj : reverseAdjList[start])
		if (!visited[adj])
			groupSCC(adj);
}

void countIndegree(int start) {
	visited[start] = true;
	for (int& adj : adjList[start]) {
		if (sccGroup[start] != sccGroup[adj])
				indegree[sccGroup[adj]] = true;

		if (!visited[adj]) {
			countIndegree(adj);
		}
	}
}

int getMinDomino() {
	int n, m;
	cin >> n >> m;

	sccIdx = 0;
	numIdx = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adjList[a].push_back(b);
		reverseAdjList[b].push_back(a);
	}

	fill(visited + 1, visited + n + 1, false);
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			checkNumber(i);

	fill(visited + 1, visited + n + 1, false);
	for (int i = numIdx - 1; i >= 0; i--) {
		if (!visited[number[i]]) {
			groupSCC(number[i]);
			sccIdx++;
		}
	}

	fill(indegree, indegree + sccIdx, false);
	fill(visited + 1, visited + n + 1, false);
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			countIndegree(i);

	int ans = 0;
	for (int i = 0; i < sccIdx; i++)
		if (!indegree[i])
			ans++;

	for (int i = 1; i <= n; i++) {
		adjList[i].clear();
		reverseAdjList[i].clear();
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
		cout << getMinDomino() << '\n';
}