// Baekjoon20154_WhoIsTheWinner.cpp
// https://www.acmicpc.net/problem/20154
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int odd = 0;
	int table[26] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1};
	for ( int i = 0; i < str.size(); i++ ) {
		if ( table[str[i] - 'A'] % 2 )
			odd++;
	}

	if ( odd % 2 )
		cout << "I\'m a winner!";
	else
		cout << "You\'re the winner?";
	cout << '\n';

	return 0;
}