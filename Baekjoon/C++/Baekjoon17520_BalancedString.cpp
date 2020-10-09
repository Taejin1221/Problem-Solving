// Baekjoon17520_BalancedString.cpp
// https://www.acmicpc.net/problem/17520
#include <iostream>

#define MOD 16769023

using namespace std;

int main(void) {
	int n;
	cin >> n;

	if ( n % 2 )
		n++;
	n /= 2;

	int ans = 1;
	for ( int i = 0; i < n; i++ )
		ans = (ans << 1) % MOD;

	cout << ans << '\n';

	return 0;
}