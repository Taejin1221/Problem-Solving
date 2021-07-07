// Baekjoon06588_Goldbach'sConjucture.cpp
// https://www.acmicpc.net/problem/6588
#include <iostream>
#include <cstring> /* memset() */
#include <cmath> /* sqrt() */

#define MAX_ARR_SIZE 1000001

using namespace std;

void Print( int n, int a, int b ) {
	cout << n << " = " << a << " + " << b << '\n';
}

int main(void) {
	ios_base::sync_with_stdio( false );
	cin.tie(NULL);
	cout.tie(NULL);

	bool prime[MAX_ARR_SIZE];
	memset( prime, true, MAX_ARR_SIZE );

	int bound = (int)sqrt(MAX_ARR_SIZE);
	for ( int i = 2; i <= bound; i++ )
		if ( prime[i] )
			for ( int j = i * i; j <= MAX_ARR_SIZE; j += i )
				prime[j] = false;

	int n;
	cin >> n;
	while ( n ) {
		bool gold = false;
		for ( int i = 3; i <= (n / 2); i++ )
			if ( prime[i] && prime[n - i] ) {
				Print( n, i, n - i );
				gold = true;
				break;
			}

		if ( !gold )
			cout << "Goldbach's conjecture is wrong.\n";

		cin >> n;
	}

	return 0;
}
