// Codeforces690_C.cpp
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while ( t-- ) {
		int x;
		cin >> x;

		if ( x < 10 )
			cout << x;
		else if ( x > 45 )
			cout << -1;
		else {
			int num = 9;
			vector<int> ans;
			while ( x != 0 ) {
				if ( x <= num ) {
					ans.push_back( x );
					x = 0;
				} else {
					ans.push_back( num );
					x -= num;
					num--;
				}
			}

			for ( int i = ans.size() - 1; i >= 0; i-- )
				cout << ans[i];
		}
		cout << '\n';
	}

	return 0;
}