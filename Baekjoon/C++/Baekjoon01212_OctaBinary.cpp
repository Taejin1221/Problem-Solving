// Baekjoon01212_OctaBinary.cpp
// https://www.acmicpc.net/problem/1212
#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string table[8] = {
		"000",
		"001",
		"010",
		"011",
		"100",
		"101",
		"110",
		"111"
	};

	string oct;
	cin >> oct;

	if ( oct == "0" )
		cout << 0;
	else {
		int isPrint = false;
		for ( char& c : table[oct[0] - '0'] ) {
			if ( !isPrint && (c == '0') )
				continue;
			else {
				isPrint = true;
				cout << c;
			}
		}
		for ( int i = 1; i < oct.size(); i++ )
			cout << table[oct[i] - '0'];
	}
	cout << endl;

	return 0;
}
