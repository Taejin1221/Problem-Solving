// LeetCode0834.cpp
// https://leetcode.com/problems/sum-of-distances-in-tree/
typedef vector<int> vi;

class Solution {
	vi ans, momOf, child;
	vector<vi> adjList;

	int dfs(int me, int mom, int distance) {
		ans[0] += distance;

		momOf[me] = mom;
		for (int& son : adjList[me])
			if (son != mom)
				child[me] += dfs(son, me, distance + 1) + 1;

		return child[me];
	}

	void fillAnswer(int curr, int n) {
		if (curr != 0)
			ans[curr] = ans[momOf[curr]] - child[curr] + (n - child[curr] - 2);

		for (int& son : adjList[curr])
			if (son != momOf[curr])
				fillAnswer(son, n);
	}

public:
	vi sumOfDistancesInTree(int n, vector<vi>& edges) {
		adjList = vector<vi> (n, vi ());
		for (int i = 0; i < edges.size(); i++) {
			adjList[edges[i][0]].push_back(edges[i][1]);
			adjList[edges[i][1]].push_back(edges[i][0]);
		}

		ans = vi (n);
		momOf = vi (n);
		child = vi (n);

		child[0] = dfs(0, -1, 0);

		fillAnswer(0, n);	

		return ans;
	}
};