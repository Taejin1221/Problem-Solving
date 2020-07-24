// LeetCode0797_AllPathFromSourceToTarget.cpp
// https://leetcode.com/problems/all-paths-from-source-to-target/
class Solution {
public:
	vector<vector<int>> ans;
	bool visited[15];

	void dfs( vector<vector<int>>& graph, vector<int> currGraph, int curr ) {
		if ( curr == graph.size() - 1 ) {
			ans.push_back( currGraph );
			return;
		}

		for ( int i = 0; i < graph[curr].size(); i++ ) {
			int next = graph[curr][i];
			if ( !visited[next] ) {
				visited[next] = true;
				currGraph.push_back( next );

				dfs( graph, currGraph, next );

				currGraph.pop_back();
				visited[next] = false;
			}
		}
	}

	vector<vector<int>> allPathsSourceTarget( vector<vector<int>>& graph ) {
		dfs( graph, { 0 }, 0 );

		return ans;
	}
};