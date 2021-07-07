// Baekjoon02501_FindCommonDivisor.cpp
// https://www.acmicpc.net/problem/2501
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;

	vector<int> divisors;
	for ( int i = 1; i <= n; i++ )
		if ( n % i == 0 )
			divisors.push_back( i );

	if ( divisors.size() < k )
		cout << 0;
	else
		cout << divisors[k - 1];
	cout << '\n';

	return 0;
}