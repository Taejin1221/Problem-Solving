// LeetCode1046_LastStoneWeight.cpp
// https://leetcode.com/problems/last-stone-weight/
class Solution {
public:
	int lastStoneWeight( vector<int>& stones ) {
		priority_queue<int> pq;

		for ( int& stone : stones )
			pq.push( stone );

		while ( pq.size() > 1 ) {
			int big1 = pq.top(); pq.pop();
			int big2 = pq.top(); pq.pop();

			int result = big1 - big2;
			if ( result )
				pq.push( result );
		}

		if ( pq.size() )
			return pq.top();
		else
			return 0;
	}
};