// Baekjoon01120_String.cpp
// https://www.acmicpc.net/problem/1120
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	int ans = 1'000'000'000;
	int distance = b.size() - a.size();
	for ( int i = 0; i <= distance; i++ ) {
		int diff = 0;
		for ( int j = 0; j < a.size(); j++ ) {
			if ( b[i + j] != a[j] )
				diff++;
		}

		ans = min( ans, diff );
	}

	cout << ans << '\n';

	return 0;
}