// LeetCode0207_CourseSchedule.cpp
// https://leetcode.com/problems/course-schedule/
class Solution {
private:
	bool hasCycle( vector<vector<int>>& adjList, vector<bool>& visited, int curr ) {
		visited[curr] = true;
		for ( int next : adjList[curr] )
			if ( visited[next] || hasCycle( adjList, visited, next ) )
				return true;

		visited[curr] = false;
		return false;
	}

public:
	bool canFinish( int numCourses, vector<vector<int>>& pre ) {
		vector<vector<int>> adjList ( numCourses );
		for ( int i = 0; i < pre.size(); i++ )
			adjList[pre[i][0]].push_back( pre[i][1] );

		vector<bool> visited ( numCourses, false );
		for ( int i = 0; i < numCourses; i++ )
			if ( hasCycle( adjList, visited, i ) )
				return false;

		return true;
	}
};