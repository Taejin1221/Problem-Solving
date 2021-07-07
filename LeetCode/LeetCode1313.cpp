// LeetCode1313_DecompressRun-LengthEncodedList.cpp
class Solution {
public:
	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> rtrnList;

		int numsSize = nums.size();

		for (int i = 1; i < numsSize; i += 2) {
			for (int j = 0; j < nums[i - 1]; j++)
				rtrnList.push_back(nums[i]);
		}

		return rtrnList;
	}

	vector<int> decompressRLElist(vector<int>& nums) {
		vector<int> rtrnList;
		int numsSize = nums.size();
		for (int i = 1; i < numsSize; i += 2) {
			vector<int> tempVec (nums[i - 1], nums[i]);

			rtrnList.insert( rtrnList.end(), tempVec.begin(), tempVec.end() );
		}

		return rtrnList;
	}
};