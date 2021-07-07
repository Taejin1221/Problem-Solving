// Baekjoon01076_Resistance.cpp
// https://www.acmicpc.net/problem/1076
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	long long val = 0;

	for ( int i = 0; i < 2; i++ ) {
		val *= 10;
		string value;
		cin >> value;

		if ( value.compare( "black" ) == 0 )
			val += 0LL;
		else if ( value.compare( "brown" ) == 0 )
			val += 1LL;
		else if ( value.compare( "red" ) == 0 )
			val += 2LL;
		else if ( value.compare( "orange" ) == 0 )
			val += 3LL;
		else if ( value.compare( "yellow" ) == 0 )
			val += 4LL;
		else if ( value.compare( "green" ) == 0 )
			val += 5LL;
		else if ( value.compare( "blue" ) == 0 )
			val += 6LL;
		else if ( value.compare( "violet" ) == 0 )
			val += 7LL;
		else if ( value.compare( "grey" ) == 0 )
			val += 8LL;
		else if ( value.compare( "white" ) == 0 )
			val += 9LL;
	}

	string multi;
	cin >> multi;
	if ( multi.compare( "black" ) == 0 )
		val *= 1LL;
	else if ( multi.compare( "brown" ) == 0 )
		val *= 10LL;
	else if ( multi.compare( "red" ) == 0 )
		val *= 100LL;
	else if ( multi.compare( "orange" ) == 0 )
		val *= 1000LL;
	else if ( multi.compare( "yellow" ) == 0 )
		val *= 10000LL;
	else if ( multi.compare( "green" ) == 0 )
		val *= 100000LL;
	else if ( multi.compare( "blue" ) == 0 )
		val *= 1000000LL;
	else if ( multi.compare( "violet" ) == 0 )
		val *= 10000000LL;
	else if ( multi.compare( "grey" ) == 0 )
		val *= 100000000LL;
	else if ( multi.compare( "white" ) == 0 )
		val *= 1000000000LL;

	cout << val << '\n';

	return 0;
}