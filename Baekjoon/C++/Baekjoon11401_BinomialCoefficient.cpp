// Baekjoon11401_BinomialCoefficient.cpp
// https://www.acmicpc.net/problem/11401
#include <iostream>

#define MOD 1'000'000'007LL

using namespace std;

typedef long long ll;

ll pow( ll a, ll exp ) {
	if ( exp == 0LL )
		return 1LL;
	else if ( exp == 1LL )
		return a;
	else {
		ll temp = pow( a, exp / 2LL );
		temp = temp * temp % MOD;
		if ( exp % 2 )
			temp = temp * a % MOD;

		return temp;
	}
}

ll fact( int a ) {
	ll result = 1LL;
	for ( int i = 1; i <= a; i++ )
		result = result * i % MOD;
	return result;
}

int main(void) {
	int n, k;
	cin >> n >> k;

	ll a = fact( n ), b = fact( k ), c = fact( n - k );

	ll ans = a * pow( b * c % MOD, MOD - 2 ) % MOD;
	cout << ans << '\n';

	return 0;
}
