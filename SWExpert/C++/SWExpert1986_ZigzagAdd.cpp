// SWExpert1986_ZigzagAdd.cpp
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	for ( int time = 1; time <= t; time++ ) {
		int n;
		cin >> n;

		int ans = 0;
		for ( int i = 1; i <= n; i++ )
			ans += ( i % 2 ) ? i : -i;

		cout << '#' << time << ' ' << ans << '\n';
	}

	return 0;
}