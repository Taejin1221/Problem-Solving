// LeetCode0055_JumpGame.cpp
// https://leetcode.com/problems/jump-game/
class Solution {
public:
	bool canJump( vector<int>& nums ) {
		bool canCome[30000] = { false, };

		canCome[0] = true;
		for ( int i = 0; i < nums.size() - 1; i++ ) {
			if ( canCome[i] ) {
				for ( int j = nums[i]; j >= 1; j-- ) {
					int next = j + i;
					if ( next < nums.size() && !canCome[next] )
						canCome[next] = true;
					else if ( canCome[next] == true )
						break;
				}
			} else
				break;
		}

		return canCome[nums.size() - 1];
	}
};