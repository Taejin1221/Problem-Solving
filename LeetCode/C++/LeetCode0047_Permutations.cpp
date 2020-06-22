// LeetCode0047_Permutations.cpp
#define VISIT true
#define UNVISIT false

class Solution {
public:
	vector<vector<int>> rtrnVector;

	vector<vector<int>> permute(vector<int>& nums) {
		int size = nums.size();

		for (int i = 0; i < size; i++) {
			helper(nums, vector<bool> (size, UNVISIT), vector<int> (0), i);
		}

		return rtrnVector;
	}

	void helper(vector<int>& nums, vector<bool> visited, vector<int> prevVector, int idx) {
		visited[idx] = VISIT;
		prevVector.push_back(nums[idx]);

		bool allVisit = true;
		int visitedSize = visited.size();
		for (int i = 0; i < visitedSize; i++) {
			if (! visited[i]) {
				allVisit = false;

				helper(nums, visited, prevVector, i);
			}
		}

		if (allVisit) {
			rtrnVector.push_back(prevVector);
		}
	}
};