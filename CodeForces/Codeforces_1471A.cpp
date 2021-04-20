// Codeforces_1471A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int n, x;
		cin >> n >> x;

		long long minVal = 0, maxVal = 0, curr;
		for ( int i = 0; i < n; i++ ) {
			cin >> curr;

			minVal += curr;
			maxVal += curr / x + ( curr % x > 0 ? 1 : 0 );
		}

		minVal = minVal / x + ( minVal %  x > 0 ? 1 : 0 );

		cout << minVal << ' ' << maxVal << '\n';
	}

	return 0;
}
