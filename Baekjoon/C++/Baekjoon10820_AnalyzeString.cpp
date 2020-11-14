// Baekjoon10820_AnalyzeString.cpp
// https://www.acmicpc.net/problem/10820
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;

	while ( getline( cin, str ) ) {
		int nums[4] = { 0, };
		for ( char& c : str ) {
			if ( 'a' <= c && c <= 'z' )
				nums[0]++;
			else if ( 'A' <= c && c <= 'Z' )
				nums[1]++;
			else if ( '0' <= c && c <= '9' )
				nums[2]++;
			else if ( c == ' ' )
				nums[3]++;
		}

		for ( int i = 0; i < 4; i++ )
			cout << nums[i] << ' ';
		cout << '\n';
	}

	return 0;
}