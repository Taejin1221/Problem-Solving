// Baekjoon10988_IsPalindrome.cpp
// https://www.acmicpc.net/problem/10988
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	bool isPalindrome = true;
	int size = str.size();
	for ( int i = 0; i < size / 2; i++ ) {
		if ( str[i] != str[size - i - 1] ) {
			isPalindrome = false;
			break;
		}
	}

	cout << ( isPalindrome ? 1 : 0 ) << '\n';

	return 0;
}