// Programmers12904_LongestPalindromeSubstring.cpp
// https://programmers.co.kr/learn/courses/30/lessons/12904
#include <string>

using namespace std;

int solution( string s ) {
	int answer = 1;

	int len = s.size();

	bool isPalin[2'500][2'500] = { false, };
	for ( int i = 0; i < len; i++ )
		isPalin[i][i] = true;

	for ( int inter = 1; inter < len; inter++ ) {
		for ( int start = 0; start < len - inter; start++ ) {
			int end = start + inter;
			if ( s[start] == s[end] ) {
				if ( inter == 1 || isPalin[start + 1][end - 1] ) {
					isPalin[start][end] = true;
					answer = max( answer, inter + 1 );
				}
			}
		}
	}

	return answer;
}