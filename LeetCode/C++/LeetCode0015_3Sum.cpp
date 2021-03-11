// LeetCode0015_3Sum.cpp
// https://leetcode.com/problems/3sum/
class Solution {
public:
	vector<vector<int>> threeSum( vector<int>& nums ) {
		int n = nums.size();

		sort( nums.begin(), nums.end() );

		vector<int> temp ( 3 );
		set<vector<int>> tempAns;
		for ( int start = 0; start < n - 2; start++ ) {
			int target = 0 - nums[start];
			temp[0] = nums[start];

			int left = start + 1, right = n - 1;
			while ( left < right ) {
				int curr = nums[left] + nums[right];
				if ( curr == target ) {
					temp[1] = nums[left];
					temp[2] = nums[right];

					tempAns.insert( temp );
				}

				if ( curr < target )
					left++;
				else
					right--;
			}
		}

		vector<vector<int>> ans;
		for ( auto iter = tempAns.begin(); iter != tempAns.end(); ++iter )
			ans.push_back( *iter );

		return ans;
	}
};