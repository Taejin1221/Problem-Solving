// LeetCode1338_ReduceArraySizeToTheHalf.cpp
// https://leetcode.com/problems/reduce-array-size-to-the-half/
class Solution {
	static bool compare(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}

public:
	int minSetSize(vector<int>& arr) {
		map<int, int> table;
		for (int& num : arr) {
			if (table.find(num) == table.end())
				table.insert({num, 1});
			else
				table.find(num)->second++;
		}

		vector<pair<int, int>> sets;
		for (auto iter = table.begin(); iter != table.end(); ++iter)
			sets.push_back(*iter);

		sort(sets.begin(), sets.end(), compare);

		int setSize = 0, ans = 0;
		for (int i = 0; setSize < arr.size() / 2; i++)
			setSize += sets[i].second, ans++;

		return ans;
	}
};