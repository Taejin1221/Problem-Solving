// Baekjoon01043.cpp
// https://www.acmicpc.net/problem/1043
#include <iostream>

#include <vector>

using namespace std;

bool isTruePeople[51], visited[51];
vector<int> adjList[51];

void dfs(int start) {
	visited[start] = true;
	isTruePeople[start] = true;

	for (int& adj : adjList[start])
		if (!visited[adj])
			dfs(adj);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> truePeoples;

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int temp;
		cin >> temp;

		isTruePeople[temp] = true;
		truePeoples.push_back(temp);
	}

	vector<int> parties[51];
	for (int i = 0; i < m; i++) {
		cin >> t;

		int prev;
		cin >> prev;

		parties[i].push_back(prev);
		for (int j = 1; j < t; j++) {
			int temp;
			cin >> temp;

			adjList[prev].push_back(temp);
			adjList[temp].push_back(prev);

			parties[i].push_back(temp);
		}
	}

	for (int& p : truePeoples)
		if (!visited[p])
			dfs(p);

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool canLie = true;
		for (int& p : parties[i]) {
			if (isTruePeople[p]) {
				canLie = false;
				break;
			}
		}

		if (canLie)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}