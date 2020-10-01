// LeetCode0933_NumberOfRecentCalls.cpp
// https://leetcode.com/problems/number-of-recent-calls/
// October LeetCoding Challenge Day 1
class RecentCounter {
public:
	queue<int> q;
	RecentCounter() {}

	int ping(int t) {
		q.push( t );
		while( !q.empty() && q.front() < t - 3000 )
			q.pop();
		return q.size();
	}
};