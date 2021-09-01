// LeetCode0565.cpp
class Solution {
	bool visited[100'000];
	int adjList[100'000];

	int dfs(int start) {
		int adj = adjList[start];
		if (!visited[adj])
			return dfs(adj) + 1;
		return 1;
	}

public:
	int arrayNesting(vector<int>& nums) {
		int n = nums.size();

		for (int i = 0; i < n; i++)
			adjList[i] = nums[i];

		int ans = 1;
		fill(visited, visited + n, false);
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				ans = max(ans, dfs(i));
			}
		}

		return ans;
	}
};