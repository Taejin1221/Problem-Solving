// LeetCode0011_ContainerWithMostWater.cpp
// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
	int maxArea( vector<int>& height ) {
		int n = height.size();

		int ans = 0;
		int left = 0, right = n - 1;
		while ( left < right ) {
			int curr = min( height[left], height[right] ) * ( right - left + 1 );
			ans = max( ans, curr );
			if ( height[left] < height[right] )
				left++;
			else
				right--;
		}

		return ans;
	}
};