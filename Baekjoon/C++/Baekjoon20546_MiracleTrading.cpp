// Baekjoon20546_MiracleTrading.cpp
// https://www.acmicpc.net/problem/20546
// IUPC G
#include <iostream>

using namespace std;

int main(void) {
	int cash;
	cin >> cash;

	int stockPrices[14];
	for ( int i = 0; i < 14; i++ )
		cin >> stockPrices[i];

	int aCash = cash, aStock = 0;
	int bCash = cash, bStock = 0;

	for ( int i = 0; i < 14; i++ ) {
		if ( stockPrices[i] <= aCash ) {
			aStock += aCash / stockPrices[i];
			aCash = aCash % stockPrices[i];
		}
	}

	int inc = 0, dec = 0;
	for ( int i = 1; i < 14; i++ ) {
		if ( stockPrices[i - 1] < stockPrices[i] ) {
			inc++;
			dec = 0;
		} else if ( stockPrices[i - 1] > stockPrices[i] ) {
			dec++;
			inc = 0;
		}

		if ( dec >= 3 ) {
			bStock += bCash / stockPrices[i];
			bCash = bCash % stockPrices[i];
		} else if ( inc >= 3) {
			bCash += bStock * stockPrices[i];
			bStock = 0;
		}

	}

	int a = aCash + aStock * stockPrices[13];
	int b = bCash + bStock * stockPrices[13];
	// cout << a << ' ' << b << '\n';
	if ( a > b )
		cout << "BNP";
	else if ( a < b )
		cout << "TIMING";
	else
		cout << "SAMESAME";
	cout << '\n';

	return 0;
}
