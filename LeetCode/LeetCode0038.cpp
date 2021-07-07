// LeetCode0038_Count-and-Say.cpp
// https://leetcode.com/problems/count-and-say/
class Solution {
public:
	string countAndSay( int n ) {
		if ( n == 1 )
			return "1";
		else {
			string prevSay = countAndSay( n - 1 );

			int saidIdx = 0;
			char said[1'000] = { 0, };

			int num = 1;
			char prevChar = prevSay[0];
			for ( int i = 1; i <= prevSay.size(); i++ ) {
				if ( i == prevSay.size() || prevChar != prevSay[i] ) {
					int tempIdx = 0;
					char temp[100] = { 0, };
					while ( num ) {
						temp[tempIdx++] = num % 10 + '0';
						num /= 10;
					}

					tempIdx--;
					while ( tempIdx >= 0 )
						said[saidIdx++] = temp[tempIdx--];

					said[saidIdx++] = prevChar;

					prevChar = prevSay[i];
				}

				num++;
			}

			return string( said );
		}
	}
};