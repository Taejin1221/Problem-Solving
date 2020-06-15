// Baekjoon02217_Rope.cpp
// https://www.acmicpc.net/problem/2217
#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
	ios_base :: sync_with_stdio( false );
	cin.tie(NULL);

	int ropes[100000];
	int n;
	cin >> n;

	for ( int i = 0; i < n; i++ )
		cin >> ropes[i];

	sort( ropes, ropes + n );

	int maxWeight = 0;
	for ( int i = 0; i < n; i++ ) {
		int currWeight = ropes[i] * (n - i);
		if ( currWeight > maxWeight )
			maxWeight = currWeight;
	}

	cout << maxWeight << '\n';

	return 0;
}