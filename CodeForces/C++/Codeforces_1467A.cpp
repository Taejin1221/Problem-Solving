// Codeforces_1467A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n;
		cin >> n;

		if ( n >= 1 )
			cout << 9;
		if ( n >= 2 )
			cout << 8;
		if ( n >= 3 )
			cout << 9;
		if( n >= 4 )
			for ( int i = 0; i < n - 3; i++ )
				cout << i % 10;

		cout << '\n';
	}

	return 0;
}
