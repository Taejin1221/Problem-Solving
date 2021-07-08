// Baekjoon17412.cpp
// https://www.acmicpc.net/problem/17412
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define MAX_ARR_SIZE 401

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> adjList[MAX_ARR_SIZE];
	int capacity[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0, };
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		adjList[s].push_back(e);
		adjList[e].push_back(s);

		capacity[s][e] += 1;
	}

	int ans = 0;
	int flowed[MAX_ARR_SIZE][MAX_ARR_SIZE] = { 0, };
	while (true) {
		int path[MAX_ARR_SIZE];
		fill(path + 1, path + n + 1, -1);

		queue<int> q;
		q.push(1);
		while (!q.empty() && path[2] == -1) {
			int curr = q.front(); q.pop();
			for (int& adj : adjList[curr]) {
				if (capacity[curr][adj] - flowed[curr][adj] > 0 && path[adj] == -1) {
					path[adj] = curr;
					q.push(adj);
					if (adj == 2)
						break;
				}
			}
		}

		if (path[2] == -1)
			break;

		for (int curr = 2; curr != 1; curr = path[curr]) {
			flowed[path[curr]][curr] += 1;
			flowed[curr][path[curr]] -= 1;
		}

		ans++;
	}

	cout << ans << '\n';

	return 0;
}