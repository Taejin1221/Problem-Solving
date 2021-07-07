// Baekjoon01475_RoomNumber.cpp
// https://www.acmicpc.net/problem/1475
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int table[10] = { 0, };
	while ( n ) {
		table[n % 10]++;
		n /= 10;
	}

	bool run = true;
	int ans = 0;
	while ( run ) {
		bool six = false, nine = false;
		for ( int i = 0; i < 10; i++ ) {
			if ( i == 6 && table[i] )
				six = true;
			if ( i == 9 && table[i] )
				nine = true;

			if ( table[i] )
				table[i]--;
		}

		if ( !six && table[9] )
			table[9]--;
		if ( !nine && table[6] )
			table[6]--;

		run = false;
		for ( int i = 0; i < 10; i++ ) 
			if ( table[i] )
				run = true;
		ans++;
	}

	cout << ans << '\n';

	return 0;
}