// Codeforces_1509A.cpp
#include <iostream>

#include <vector>

using namespace std;

void solveTestCase( ) {
	int n;
	cin >> n;

	vector<int> even, odd;
	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;

		if ( temp % 2 )
			odd.push_back( temp );
		else
			even.push_back( temp );
	}

	for ( int& val : even )
		cout << val << ' ';
	for ( int& val : odd )
		cout << val << ' ';
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
