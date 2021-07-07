// LeetCode0401_BinaryWatch.cpp
// https://leetcode.com/problems/binary-watch/
class Solution {
private:
	set<string> result;
	void backtracking( int currNum, int h, int m ) {
		if ( h > 12 || m > 59 ) {
			return;
		}
		else if ( currNum == 0 ) {
			string time = to_string( h );

			time += string(":");

			if ( m < 10 ) {
				time += string("0");
				time += to_string(m);
			} else {
				time += to_string( m );
			}

			result.insert( time );
		} else {
			for ( int i = 0; i < 4; i++ )
				if ( !( h & ( 1 << i ) ) )
					backtracking( currNum - 1, h + (1 << i), m );

			for ( int i = 0; i < 6; i++ )
				if ( !( m & ( 1 << i ) ) )
					backtracking( currNum - 1, h, m + (1 << i) );
		}
	}

public:
	vector<string> readBinaryWatch( int num ) {
		backtracking( num, 0, 0 );
		vector<string> ans;
		for ( auto iter = result.begin(); iter != result.end(); ++iter )
			ans.push_back( *iter );

		return ans;
	}
};