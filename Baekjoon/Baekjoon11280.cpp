// Baekjoon11280.cpp
// https://www.acmicpc.net/problem/11280
#include <iostream>

#include <stack>
#include <vector>
#include <algorithm>

#define SIZE 20'001

using namespace std;

stack<int> stck;
vector<int> adjList[SIZE], reverseList[SIZE];
int sccGroup[SIZE];
bool visited[SIZE];

void makeGraph(int n, int m);
void dfs1(int start);
void dfs2(int start, int group);
void getSCC(int n);

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	makeGraph(n, m);
	getSCC(n);

	int ans = 1;
	for (int i = 1; i <= n; i++) {
		if (sccGroup[i] == sccGroup[i + n]) {
			ans = 0;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}

void makeGraph(int n, int m) {
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if (a > 0 && b > 0) {
			adjList[a + n].push_back(b);
			adjList[b + n].push_back(a);

			reverseList[b].push_back(a + n);
			reverseList[a].push_back(b + n);
		} else if (a > 0 && b < 0) {
			b *= -1;
			adjList[a + n].push_back(b + n);
			adjList[b].push_back(a);

			reverseList[b + n].push_back(a + n);
			reverseList[a].push_back(b);
		} else if (a < 0 && b > 0) {
			a *= -1;
			adjList[a].push_back(b);
			adjList[b + n].push_back(a + n);

			reverseList[b].push_back(a);
			reverseList[a + n].push_back(b + n);
		} else {
			a *= -1, b *= -1;
			adjList[a].push_back(b + n);
			adjList[b].push_back(a + n);

			reverseList[b + n].push_back(a);
			reverseList[a + n].push_back(b);
		}
	}
}

void dfs1(int start) {
	visited[start] = true;

	for (int& adj : adjList[start])
		if (!visited[adj])
			dfs1(adj);

	stck.push(start);
}

void dfs2(int start, int group) {
	sccGroup[start] = group;

	for (int& adj : reverseList[start])
		if (sccGroup[adj] == 0)
			dfs2(adj, group);
}

void getSCC(int n) {
	for (int i = 1; i <= 2 * n; i++)
		if (!visited[i])
			dfs1(i);

	int group = 1;
	while (stck.size()) {
		int curr = stck.top(); stck.pop();
		if (sccGroup[curr] == 0) {
			dfs2(curr, group);
			group++;
		}
	}
}