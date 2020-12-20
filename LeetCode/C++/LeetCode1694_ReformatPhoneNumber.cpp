// LeetCode1694_ReformatPhoneNumber.cpp
// https://leetcode.com/problems/reformat-phone-number/
// LeetCode Weekly Contest 220
class Solution {
public:
	string reformatNumber( string number ) {
		char onlyNumber[101];

		int len = 0;
		for ( char& c : number )
			if ( '0' <= c && c <= '9' )
				onlyNumber[len++] = c;

		int onlyIdx = 0, rightIdx = 0;
		char rightNumber[1'000] = { 0, };
		while ( len - onlyIdx > 4 ) {
			for ( int i = 0; i < 3; i++ )
				rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
			rightNumber[rightIdx++] = '-';
		}

		if ( len - onlyIdx == 4 ) {
			rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
			rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
			rightNumber[rightIdx++] = '-';
			rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
			rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
		} else if ( len - onlyIdx == 0 ) {
			rightNumber[rightIdx] = 0;
		} else {
			int diff = len - onlyIdx;
			for ( int i = 0; i < diff; i++ )
				rightNumber[rightIdx++] = onlyNumber[onlyIdx++];
		}

		return string( rightNumber );
	}
};
