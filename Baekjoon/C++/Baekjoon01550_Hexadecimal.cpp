// Baekjoon01550_Hexadecimal.cpp
// https://www.acmicpc.net/problem/1550
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string hex;
	cin >> hex;

	int ans = 0;
	for ( char& c : hex ) {
		ans *= 16;

		int num;
		if ( '0' <= c && c <= '9' )
			num = c - '0';
		else
			num = c - 'A' + 10;
		ans += num;
	}

	cout << ans << '\n';

	return 0;
}