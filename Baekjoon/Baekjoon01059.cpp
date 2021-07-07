// Baekjoon01059_GoodInterval.cpp
// https://www.acmicpc.net/problem/1059
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
	cin >> l;

	int s[50], minVal = 1'000, maxVal = 1;
	for ( int i = 0; i < l; i++ ) {
		cin >> s[i];
		minVal = min( minVal, s[i] );
		maxVal = max( maxVal, s[i] );
	}

	int n;
	cin >> n;

	int a, b;
	if ( minVal > n ) {
		a = 0;
		b = minVal;
	} else if ( maxVal < n ) {
		a = minVal;
		b = 1'001;
	} else {
		a = minVal, b = maxVal;
		for ( int i = 0; i < l; i++ ) {
			if ( s[i] < n )
				a = max( a, s[i] );
			else
				b = min( b, s[i] );
		}
	}

	if ( a == n || b == n )
		cout << "0";
	else
		cout << ( b - n ) * ( n - a ) - 1;
	cout << '\n';

	return 0;
}