// Codeforces_1485A.cpp
#include <iostream>

using namespace std;

void solveTestCase( ) {
	int a, b;
	cin >> a >> b;

	int ans = 1'000'000'000;
	for ( int i = 0; i <= 1'000'000'000 - b; i++ ) {
		int newB = b + i;
		if ( i > ans )
			break;

		if ( newB == 1 )
			continue;
		else {
			int currAns = i;
			for ( long long newA = 1; newA <= a; newA *= newB )
				currAns++;

			ans = min( currAns, ans );
		}
	}

	cout << ans << '\n';
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
