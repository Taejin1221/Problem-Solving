// Baekjoon06359_DrunkenSangbum.cpp
// https://www.acmicpc.net/problem/6359
#include <iostream>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;

		bool isClose[101] = { false, };
		for ( int i = 2; i <= n; i++ ) {
			for ( int j = i; j <= n; j += i )
				isClose[j] = !isClose[j];
		}

		int ans = 0;
		for ( int i =  1; i <= n; i++ )
			if ( !isClose[i] )
				ans++;

		cout << ans << '\n';
	}

	return 0;
}
