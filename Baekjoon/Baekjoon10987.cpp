// Baekjoon10987_NumberOfVowel.cpp
// https://www.acmicpc.net/problem/10987
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int num = 0;
	for ( char& c : str )
		if ( (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') )
			num++;

	cout << num << '\n';

	return 0;
}