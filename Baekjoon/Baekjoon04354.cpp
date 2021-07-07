// Baekjoon04354_PowerStrings.cpp
// https://www.acmicpc.net/problem/4354
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	while ( str != "." ) {
		int n = str.size();
		int fail[1'000'000] = { 0, };

		int j = 0;
		for ( int i = 1; i < n; i++ ) {
			while ( j > 0 && str[i] != str[j] )
				j = fail[j - 1];

			if ( str[i] == str[j] )
				fail[i] = ++j;
		}

		int aSize = n - fail[n - 1];
		if ( fail[n - 1] % aSize == 0 )
			cout << n / aSize;
		else
			cout << 1;
		cout << '\n';

		cin >> str;
	}

	return 0;
}