// Baekjoon01918_PostfixExrpession.cpp
// https://www.acmicpc.net/problem/1918
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetPriority( char c ) {
	if ( c == '*' || c == '/' )
		return 1;
	else
		return 2;
}

int main(void) {
	string prefix;
	cin >> prefix;

	vector<char> stck;
	for ( char& c : prefix ) {
		if ( 'A' <= c && c <= 'Z' )
			cout << c;
		else if ( c == '(' )
			stck.push_back( c );
		else if ( c == ')' ) {
			while ( stck.back() != '(' ) {
				cout << stck.back(); stck.pop_back();
			}
			stck.pop_back();
		} else {
			int c_prior = GetPriority( c );
			while ( !stck.empty() && stck.back() != '(' && c_prior >= GetPriority( stck.back() ) ) {
				cout << stck.back(); stck.pop_back();
			}
			stck.push_back( c );
		}
	}

	while ( !stck.empty() ) {
		cout << stck.back(); stck.pop_back();
	}

	cout << '\n';

	return 0;
}