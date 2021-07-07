// Baekjoon02960_SieveOfEratosthenes.cpp
// https://www.acmicpc.net/problem/2960
#include <iostream>
#include <algorithm> /* fill() */

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	bool sieve[1001];
	fill( sieve, sieve + 1001, true );

	int ans;
	for ( int i = 2; i <= n; i++ ) {
		if ( sieve[i] ) {
			k--;
			if ( k == 0 ) {
				ans = i;
				break;
			}
			
			for ( int j = i * i; j <= n; j += i ) {
				if ( sieve[j] ) {
					k--;
					sieve[j] = false;
				}

				if ( k == 0 ) {
					ans = j;
					break;
				}
			}

			if ( k == 0 )
				break;
		}
	}

	cout << ans << '\n';

	return 0;
}