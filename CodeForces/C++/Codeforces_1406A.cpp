// Codeforces670_A.cpp
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

		int table[101] = { 0, };
		for ( int i = 0; i < n; i++ ) {
			int temp;
			cin >> temp;
			table[temp]++;
		}

		int mex[2];
		for ( int time = 0; time < 2; time++ ) {
			for ( int i = 0; i <= 100; i++ ) {
				if ( table[i] )
					table[i]--;
				else {
					mex[time] = i;
					break;
				}
			}
		}

		cout << mex[0] + mex[1] << endl;
	}

	return 0;
}