// Baekjoon15711_BestCouple.cpp
// https://www.acmicpc.net/problem/15711
// reference: https://m.blog.naver.com/PostView.nhn?blogId=rdd573&logNo=221270230610&proxyReferer=https:%2F%2Fwww.google.com%2F
#include <iostream>
#include <cstring> /* memset() */
#include <vector>

#define MAX_ARR_SIZE 2000001

typedef long long ll;

using namespace std;

bool prime[MAX_ARR_SIZE];
vector<int> primes;

bool isPrime( ll a ) {
	for ( int i = 0; i < (int)primes.size() && ((ll)primes[i] * primes[i] <= a); i++ )
		if ( (a % primes[i] == 0) )
			return false;
	return true;
}

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	memset( prime, true, MAX_ARR_SIZE );

	prime[0] = false, prime[1] = false;
	for ( int i = 2; i * i <= MAX_ARR_SIZE; i++ )
		if ( prime[i] )
			for ( int j = i * i; j <= MAX_ARR_SIZE; j += i )
				prime[j] = false;

	for ( int i = 2; i < MAX_ARR_SIZE; i++ )
		if ( prime[i] )
			primes.push_back( i );

	int t;
	cin >> t;
	for ( int i = 0; i < t; i++ ) {
		ll a, b;
		cin >> a >> b;
		ll n = a + b;

		bool gold = false;
		if ( n >= 4 ) {
			if ( n % 2 == 0 )
				gold = true;
			else if ( isPrime( n - 2 ) )
				gold = true;
		}

		if ( gold )
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}
