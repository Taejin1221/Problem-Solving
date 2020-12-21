// Codeforces_Educational_100_A.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		int m1, m2, m3;
		cin >> m1 >> m2 >> m3;

		int sum = m1 + m2 + m3;
		int minVal = min( m1, min( m2, m3 ) );

		if ( sum % 9 == 0 && minVal >= sum / 9 )
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
