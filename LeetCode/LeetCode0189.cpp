// LeetCode0189_RotateArray.cpp
// https://leetcode.com/problems/rotate-array/
class Solution {
public:
	void rotate( vector<int>& nums, int k ) {
		k %= nums.size();

		deque<int> dq;
		for ( int&n : nums )
			dq.push_back( n );

		while ( k-- ) {
			dq.push_front( dq.back() );
			dq.pop_back();
		}

		int idx = 0;
		for ( deque<int>::iterator iter = dq.begin(); iter != dq.end(); ++iter )
			nums[idx++] = *iter;
	}
};