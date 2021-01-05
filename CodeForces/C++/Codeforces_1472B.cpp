// Codeforces_1472B.cpp
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

		int total = 0;
		int one = 0, two = 0;
		for ( int i = 0; i < n; i++ ) {
			int temp;
			cin >> temp;

			if ( temp == 1 )
				one++;
			else
				two++;
			total += temp;
		}

		if ( total % 2 )
			cout << "NO";
		else {
			int alice = 0, bob = 0;
			if ( two % 2 == 1 )
				one -= 2;

			if ( one < 0 )
				cout << "NO";
			else
				cout << "YES";
		}
		cout << '\n';
	}

	return 0;
}
