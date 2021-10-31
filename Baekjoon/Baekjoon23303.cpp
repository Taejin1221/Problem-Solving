// Baekjoon23303.cpp
// https://www.acmicpc.net/problem/23303
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	bool canRate = false;
	for (int i = 0; i < (int)str.size() - 1; i++) {
		if ((str[i] == 'D' || str[i] == 'd') && str[i + 1] == '2') {
			canRate = true;
			break;
		}
	}

	cout << (canRate ? "D2" : "unrated") << '\n';

	return 0;
}