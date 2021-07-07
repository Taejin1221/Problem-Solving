// Baekjoon01351_InfinitySequence.cpp
// https://www.acmicpc.net/problem/1351
#include <iostream>

#include <map>

using namespace std;

typedef long long ll;

ll p, q;
map<ll, ll> dp;

ll getNum( ll n ) {
	if ( n == 0 )
		return 1;

	if ( dp.find( n ) == dp.end() ) {
		dp.insert( { n, getNum( n / p ) + getNum( n / q ) } );
	}

	return dp[n];
}

int main(void) {
	ll n;
	cin >> n >> p >> q;

	cout << getNum( n ) << '\n';

	return 0;
}