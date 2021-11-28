// Baekjoon23738.cpp
// https://www.acmicpc.net/problem/23738
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string table[128];
	table['A'] = "a";
	table['B'] = "v";
	table['E'] = "ye";
	table['K'] = "k";
	table['M'] = "m";
	table['H'] = "n";
	table['O'] = "o";
	table['P'] = "r";
	table['C'] = "s";
	table['T'] = "t";
	table['Y'] = "u";
	table['X'] = "h";

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		cout << table[str[i]];
	}

	cout << '\n';

	return 0;
}