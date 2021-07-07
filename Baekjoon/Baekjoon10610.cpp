// Baekjoon10610_30.cpp
// https://www.acmicpc.net/problem/10610
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare( char a, char b ) {
	return a > b;
}

int main(void) {
	char n[100'001] = { 0, };
	cin >> n;

	int len = strlen( n );
	sort( n, n + len, compare );
	if ( n[len - 1] != '0' )
		cout << -1;
	else {
		int sum = 0;
		for ( int i = 0; i < len - 1; i++ )
			sum += n[i] - '0';

		if ( sum % 3 )
			cout << -1;
		else
			cout << n;
	}
	cout << '\n';

	return 0;
}
