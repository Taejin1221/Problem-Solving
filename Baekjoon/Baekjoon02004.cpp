// Baekjoon02004_NumberOf0InCombination.cpp
// https://www.acmicpc.net/problem/2004
#include <iostream>

#define MAX 2'000'000'000

using namespace std;

int main(void) {
	int n, p, q;
	cin >> n >> p;
	q = n - p;

	int twoes[3] = { 0, };
	long power2 = 2;
	while ( power2 < MAX ) {
		twoes[0] += n / power2;
		twoes[1] += p / power2;
		twoes[2] += q / power2;

		power2 *= 2;
	}


	int fives[3] = { 0, };
	long power5 = 5;
	while ( power5 < MAX ) {
		fives[0] += n / power5;
		fives[1] += p / power5;
		fives[2] += q / power5;

		power5 *= 5;
	}

	int num2 = twoes[0] - twoes[1] - twoes[2];
	int num5 = fives[0] - fives[1] - fives[2];
	if ( num2 <= 0 || num5 <= 0 )
		cout << 0 << '\n';
	else
		cout << min( num2, num5 ) << '\n';

	return 0;
}