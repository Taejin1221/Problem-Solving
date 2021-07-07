// Baekjoon15353_BigInterger2.cpp
// https://www.acmicpc.net/problem/15353
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> a, b;

	for ( int i = s1.size() - 1; i >= 0; i-- )
		a.push_back( s1[i] - '0' );

	for ( int i = s2.size() - 1; i >= 0; i-- )
		b.push_back( s2[i] - '0' );

	vector<int> c;
	int idx, carry = 0;
	for ( idx = 0; idx < s1.size() && idx < s2.size(); idx++ ) {
		int value = a[idx] + b[idx] + carry;
		c.push_back( value % 10 );
		carry = value / 10;
	}

	for ( ; idx < s1.size(); idx++ ) {
		int value = a[idx] + carry;
		c.push_back( value % 10 );
		carry = value / 10;
	}

	for ( ; idx < s2.size(); idx++ ) {
		int value = b[idx] + carry;
		c.push_back( value % 10 );
		carry = value / 10;
	}

	if ( carry )
		c.push_back( carry );

	for ( int i = c.size() - 1; i >= 0; i-- )
		cout << c[i];
	cout << '\n';

	return 0;
}