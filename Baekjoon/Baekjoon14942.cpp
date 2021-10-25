// Baekjoon14942.cpp
// https://www.acmicpc.net/problem/14942
#include <iostream>

#include <vector>

#define idx first
#define cost second
#define SIZE 100'001

using namespace std;

typedef pair<int, int> pii;

int closestRoom[SIZE], energy[SIZE];
vector<pii> adjList[SIZE];

int binarySearch(vector<pii>& costs, int currEnergy) {
	int lastValue = costs.back().cost;

	int left = 0, right = costs.size() - 1;
	while (left + 1 < right) {
		int mid = (left + right) / 2;

		int currTarget = lastValue - costs[mid - 1].cost;
		if (currTarget <= currEnergy) {
			right = mid;
		} else {
			left = mid;
		}
	}

	if (lastValue - costs[right - 1].cost > currEnergy)
		return -1;
	else
		return right;
}

void dfs(int me, int mom, vector<pii>& costs) {
	int closestIdx = binarySearch(costs, energy[me]);
	if (closestIdx == -1)
		closestRoom[me] = me;
	else
		closestRoom[me] = costs[closestIdx].idx;

	for (pii& adj : adjList[me]) {
		if (adj.idx != mom) {
			costs.push_back({ me, costs.back().cost + adj.cost });
			dfs(adj.idx, me, costs);
			costs.pop_back();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> energy[i];

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adjList[a].push_back({ b, c });
		adjList[b].push_back({ a, c });
	}

	vector<pii> costs { { 0, 0 } };
	dfs(1, 0, costs);

	closestRoom[1] = 1;
	for (int i = 1; i <= n; i++)
		cout << closestRoom[i] << '\n';

	return 0;
}