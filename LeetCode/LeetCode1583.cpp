// LeetCode1583_CountUnhappyFriends.cpp
// https://leetcode.com/problems/count-unhappy-friends/
// LeetCode Weekly Contest 206
class Solution {
private:
	bool isUnhappy( vector<vector<int>>& prefer, vector<int> table, int me ) {
		for ( int check = 0; prefer[me][check] != table[me]; check++ ) {
			int currCheck = prefer[me][check];
			for ( int i = 0; prefer[currCheck][i] != table[currCheck]; i++ )
				if ( prefer[currCheck][i] == me )
					return true;
		}

		return false;
	}

public:
	int unhappyFriends( int n, vector<vector<int>>& prefer, vector<vector<int>>& pairs ) {
		int ans = 0;

		vector<int> table ( n );
		for ( int i = 0; i < pairs.size(); i++ ) {
			table[pairs[i][0]] = pairs[i][1];
			table[pairs[i][1]] = pairs[i][0];
		}

		for ( int i = 0; i < n; i++ )
			if ( isUnhappy( prefer, table, i ) )
				ans++;

		return ans;
	}
};