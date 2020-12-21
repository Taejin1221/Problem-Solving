// Codeforces_692_B.cpp
#include <iostream>

using namespace std;

typedef long long ll;

bool isValid( ll num ) {
	ll temp = num;
	while ( temp ) {
		int digit = temp % 10;
		if ( digit != 0 )
			if ( num % digit != 0 )
				return false;
		temp /= 10;
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while ( t-- ) {
		ll n;
		cin >> n;

		while ( !isValid( n++ ) );
		
		cout << --n << '\n';
	}

	return 0;
}
