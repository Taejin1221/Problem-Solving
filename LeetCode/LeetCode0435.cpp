// LeetCode0435_NonOverlappingIntervals.cpp
// https://leetcode.com/problems/non-overlapping-intervals/
// August Leetcoding Challenge Day 15
class Solution {
private:
	static bool compare( const vector<int>& v1, const vector<int>& v2 ) {
		return v1[1] < v2[1];
	}

public:
	int eraseOverlapIntervals( vector<vector<int>>& intervals ) {
		if ( intervals.size() == 0 )
			return 0;

		sort( intervals.begin(), intervals.end(), compare );

		int count = 0;
		vector<int>& prev = intervals[0];
		for ( int i = 1; i < intervals.size(); i++ ) {
			if ( prev[1] > intervals[i][0] )
				count++;
			else
				prev = intervals[i];
		}

		return count;
	}
};
