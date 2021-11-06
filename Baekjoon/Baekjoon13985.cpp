// Baekjoon13985.cpp
// https://www.acmicpc.net/problem/13985
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string question;
	getline(cin, question);

	// cout << (question[0] - '0') << (question[4]) << (question[8]) << endl;
	if ((question[0] - '0') + (question[4] - '0') == (question[8] - '0'))
		cout << "YES";
	else
		cout << "NO";
	cout << '\n';

	return 0;
}