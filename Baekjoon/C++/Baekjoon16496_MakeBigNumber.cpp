// Baekjoon16496_MakeBigNumber.cpp
// https://www.acmicpc.net/problem/16496
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

bool Compare( string& s1, string& s2 ) {
	if ( s2 + s1 < s1 + s2 )
		return true;
	else
		return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	string numbers[1'000];
	for ( int i = 0; i < n; i++ )
		cin >> numbers[i];

	sort( numbers, numbers + n, Compare );

	if ( numbers[0][0] == '0' )
		cout << '0';
	else {
		for ( int i = 0; i < n; i++ )
			cout << numbers[i];
	}

	cout << '\n';

	return 0;
}