// Baekjoon10808_NumberOfAlphabet.cpp
// https://www.acmicpc.net/problem/10808
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int table[26] = { 0, };
	for ( char& c : str )
		table[c - 'a']++;

	for ( int i = 0; i < 26; i++ )
		cout << table[i] << ' ';
	cout << '\n';

	return 0;
}