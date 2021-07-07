// LeetCode0056_MergeIntervals.cpp
// https://leetcode.com/problems/merge-intervals/
bool compare( const vector<int> v1, const vector<int> v2 ) {
	if ( v1[0] != v2[0] )
		return v1[0] < v2[0];
	else
		return v1[1] < v2[1];
}

class Solution {
public:
	vector<vector<int>> merge( vector<vector<int>>& intervals ) {
		sort( intervals.begin(), intervals.end(), compare );

		int start = intervals[0][0], end = intervals[0][1];
		vector<vector<int>> answer;
		for ( int i = 0; i < intervals.size() - 1; i++ ) {
			if ( intervals[i][1] >= intervals[i + 1][0] )
				end = intervals[i + 1][1];
			else {
				answer.push_back( vector<int> { start, end } );
				if ( i != intervals.size() - 1 ) {
					start = intervals[i + 1][0];
					end = intervals[i + 1][1];
				}
			}
		}

		answer.push_back( vector<int> { start, end } );

		return answer;
	}
};