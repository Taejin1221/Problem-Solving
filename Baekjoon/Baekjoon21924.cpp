// Baekjoon21924.cpp
// https://www.acmicpc.net/problem/21924
#include <iostream>

#include <algorithm>

using namespace std;

using ll = long long;

struct Edge {
	int v1, v2;
	int cost;
	
	Edge(): v1(0), v2(0), cost(0) {}
	
	bool operator<(const Edge& e2) const {
		return cost < e2.cost;
	}
};

int parent[100001];

int findRoot(int me) {
	return me == parent[me]? me : parent[me] = findRoot(parent[me]);
}

void unionTwo(int aRoot, int bRoot) {
	if (aRoot < bRoot)
		parent[bRoot] = aRoot;
	else
		parent[aRoot] = bRoot;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	ll totalCost = 0;
	Edge edges[500000];
	for (int i = 0; i < m; i++) {
		Edge& currEdge = edges[i];
		cin >> currEdge.v1 >> currEdge.v2 >> currEdge.cost;

		totalCost += currEdge.cost;
	}

	sort(edges, edges + m);

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		Edge currEdge = edges[i];

		int aRoot = findRoot(currEdge.v1), bRoot = findRoot(currEdge.v2);
		if (aRoot != bRoot) {
			unionTwo(aRoot, bRoot);
			ans += currEdge.cost;
		}
	}

	int targetRoot = findRoot(1);
	bool isAllConnected = true;
	for (int i = 2; i <= n; i++) {
		if (targetRoot != findRoot(i)) {
			isAllConnected = false;
			break;
		}
	}

	if (isAllConnected)
		cout << totalCost - ans;
   else
   		cout << -1;
	cout << '\n';

	return 0;
}
