// Codeforces_1514A.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int n;
	cin >> n;

	int notSquare = 0;
	for ( int i = 0; i < n; i++ ) {
		int curr;
		cin >> curr;

		bool isSquare = false;
		for ( int i = 1; i * i <= curr; i++ ) {
			if ( i * i == curr ) {
				isSquare = true;
				break;
			}
		}

		if ( !isSquare )
			notSquare++;
	}

	if ( notSquare > 0 )
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';
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
