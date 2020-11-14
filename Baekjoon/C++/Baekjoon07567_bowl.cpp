// Baekjoon07567_bowl.cpp
// https://www.acmicpc.net/problem/7567
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string bowls;
	cin >> bowls;

	int height = 0;

	char prev = '\0';
	for ( char& c : bowls ) {
		if ( c == '(' ) {
			if ( !prev || prev == ')' )
				height += 10;
			else
				height += 5;
		} else {
			if ( !prev || prev == '(' )
				height += 10;
			else
				height += 5;
		}

		prev = c;
	}

	cout << height << '\n';

	return 0;
}