// Codeforces_1480A.cpp
#include <iostream>

#include <cstring>

using namespace std;

void solveTestCase( ) {
	char str[51];
	cin >> str;

	int n = strlen( str );
	for ( int i = 0; i < n; i++ ) {
		if ( i % 2 ) { // Bob
			if ( str[i] == 'z' )
				str[i] = 'y';
			else
				str[i] = 'z';
		} else { // Alice
			if ( str[i] == 'a' )
				str[i] = 'b';
			else
				str[i] = 'a';
		}
	}

	cout << str << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		solveTestCase( );
	}

	return 0;
}
