// Baekjoon15904_WhatIsAbbreviationOfUCPC.cpp
// https://www.acmicpc.net/problem/15904
// UCPC 2018 Preliminary G
#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char str[1000], UCPC[5] = "UCPC";
	cin.getline( str, 1000 );

	int len = strlen( str );

	int idx = 0;
	for ( int i = 0; i < len; i++ )
		if ( str[i] == UCPC[idx] )
			idx++;

	if ( idx == 4 )
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";

	return 0;
}