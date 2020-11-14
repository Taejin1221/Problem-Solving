// Baekjoon20001_RubberDuckDebugging.cpp
// https://www.acmicpc.net/problem/20001
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline( cin, str );

	string end = "고무오리 디버깅 끝";

	int prob = 0;
	getline( cin, str );
	while ( str.compare( end ) != 0) {
		if ( str.compare( "문제" ) == 0 )
			prob++;
		else if ( str.compare( "고무오리" ) == 0 ) {
			if ( prob == 0 )
				prob += 2;
			else
				prob--;
		}

		getline( cin, str );
	}

	if ( prob == 0 )
		cout << "고무오리야 사랑해";
	else
		cout << "힝구";
	cout << '\n';

	return 0;
}