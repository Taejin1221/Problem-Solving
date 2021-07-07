// Baekjoon02902_WhyKMPisKMP.cpp
// https://www.acmicpc.net/problem/2902
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	string ans = "";
	for ( char& c : str ) {
		if ( 'A' <= c && c <= 'Z' )
			ans += c;
	}

	cout << ans << endl;

	return 0;
}