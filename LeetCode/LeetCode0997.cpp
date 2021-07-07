// LeetCode0997_FindTheTownJudge.cpp
// https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
	int findJudge( int N, vector<vector<int>>& trust ) {
		vector<int> inEdges( N + 1 );
		vector<int> outEdges( N + 1 );

		for ( int i = 0; i < trust.size(); i++ ) {
			outEdges[trust[i][0]]++;
			inEdges[trust[i][1]]++;
		}

		int ans = -1;
		for ( int i = 1; i <= N; i++ ) {
			if ( inEdges[i] == N - 1 && outEdges[i] == 0 ) {
				ans = i;
				break;
			}
		}

		return ans;
	}
};