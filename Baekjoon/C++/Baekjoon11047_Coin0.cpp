// Baekjoon11047_Coin0.cpp
// https://www.acmicpc.net/problem/11047
#include <iostream>

using namespace std;

int num;
int coins[10];
void CoinNum( int price, int idx ) {
	if ( idx < 0 )
		return;
	else if ( price > 0 ) {
		int temp = price / coins[idx];
		num += temp;

		if ( temp == 0 )
			CoinNum( price, idx - 1 );
		else
			CoinNum( price % (coins[idx] * temp), idx - 1 );
	}
}

int main(void) {
	int n, k, initIdx;
	cin >> n >> k;
	initIdx = n - 1;

	for ( int i = 0; i < n; i++ ) {
		int temp;
		cin >> temp;
		if ( temp > k ) {
			initIdx = i - 1;
			break;
		}
		else
			coins[i] = temp;
	}

	CoinNum( k, initIdx );

	cout << num << '\n';

	return 0;
}