// Baekjoon01644_ContiguousSumOfPrime.cpp
// https://www.acmicpc.net/problem/1644
#include <iostream>
#include <cstring> /* memset() */
#include <vector>

#define MAX_ARR_SIZE 4000001

using namespace std;

int main(void) {
	int n;
	cin >> n;

	bool prime[MAX_ARR_SIZE];
	memset( prime, true, MAX_ARR_SIZE );

	for ( int i = 2; i <= n / i; i++ )
		if ( prime[i] )
			for ( int j = i * i; j <= n; j += i )
				prime[j] = false;

	vector<int> primes;
	for ( int i = 2; i <= n; i++ )
		if ( prime[i] )
			primes.push_back( i );

	int count = 0;
	int start = 0, end = 0, sum = 2;
	while ( end < primes.size() ) {
		if ( sum == n )
			count++;

		if ( sum < n)
			sum += primes[++end];
		else
			sum -= primes[start++];

	}

	cout << count << '\n';

	return 0;
}
