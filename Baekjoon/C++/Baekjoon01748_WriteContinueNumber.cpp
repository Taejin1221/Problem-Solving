// Baekjoon01748_WriteContinueNumber.cpp
// https://www.acmicpc.net/problem/1748
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	long long sum = 0;
	for ( int i = 1; i <= n; i++ ) {
		if ( 1 <= i && i <= 9 )
			sum++;
		else if ( 10 <= i && i <= 99 )
			sum += 2;
		else if ( 100 <= i && i <= 999 )
			sum += 3;
		else if ( 1'000 <= i && i <= 9'999 )
			sum += 4;
		else if ( 10'000 <= i && i <= 99'999 )
			sum += 5;
		else if ( 100'000 <= i && i <= 999'999 )
			sum += 6;
		else if ( 1'000'000 <= i && i <= 9'999'999 )
			sum += 7;
		else if ( 10'000'000 <= i && i <= 99'999'999 )
			sum += 8;
		else
			sum += 9;
	}

	cout << sum << '\n';

	return 0;
}