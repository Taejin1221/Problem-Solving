// Baekjoon01013_Contact.cpp
// https://www.acmicpc.net/problem/1013
#include <iostream>

using namespace std;

bool solvedTestCase( char* str ) {
	if ( !str[0] )
		return true;

	if ( str[0] == '1' ) {
		int idx = 1;
		for ( ; str[idx] && str[idx] == '0'; idx++ );

		if ( !str[idx] || idx <= 2 )
			return false;
		else {
			int curr = idx, next = idx + 1;
			if ( !str[next] )
				return true;
			else {
				if ( str[next] == '0' )
					return solvedTestCase( str + next );
				else {
					for ( ; str[next] && str[next] == '1'; next++ );

					if ( !str[next] )
						return true;
					else {
						curr = next - 1; // str[curr] is last one
						if ( str[next + 1] ) {
							if ( str[next + 1] == '0' )
								return solvedTestCase( str + curr );
							else
								return solvedTestCase( str + next );
						} else
							return false;
					}
				}
			}
		}
	} else {
		if ( str[1] && str[1] == '1' ) // "01"
			return solvedTestCase( str + 2 );
		else
			return false;
	}
}

int main(void) {
	int t;
	cin >> t;

	while ( t-- ) {
		char str[201];
		cin >> str;

		if ( solvedTestCase( str ) )
			cout << "YES";
		else
			cout << "NO";
		cout << '\n';
	}

	return 0;
}