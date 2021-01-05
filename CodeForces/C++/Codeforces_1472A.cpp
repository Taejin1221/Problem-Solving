// Codeforces_1472A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int w, h, n;
		cin >> w >> h >> n;

		int total = 1;
		while ( w % 2 == 0 ) {
			total += total;
			w /= 2;
		}

		while ( h % 2 == 0 ) {
			total += total;
			h /= 2;
		}

		if ( total >= n )
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}
