// LeetCode0338_CountingBits.cpp
// https://leetcode.com/problems/counting-bits/
class Solution {
public:
	// Method 1
	vector<int> countBits( int num ) {
		vector<int> ans (num + 1);

		ans[0] = 0;
		if ( num != 0 ) {
			ans[1] = 1;
			for ( int i = 1; i <= (num / 2); i++ ) {
				ans[i * 2] = ans[i];
				if ( (i * 2 + 1 ) <= num )
					ans[i * 2 + 1] = ans[i] + 1;
			}
		}

		return ans;
	}

	// Method 2
	vector<int> countBits( int num ) {
		vector<int> ans (num + 1 );
		if ( num ) {
			ans[1] = 1;
			for ( int i = 2; i <= num; i++ )
				ans[i] = ans[i / 2] + (i % 2);
		}

		return ans;
	}
};