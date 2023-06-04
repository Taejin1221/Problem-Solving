// Baekjoon27866.cpp
// https://www.acmicpc.net/problem/27866
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int i;
	cin >> i;

	cout << str[--i] << '\n';

	return 0;
}