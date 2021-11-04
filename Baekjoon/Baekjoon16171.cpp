// Baekjoon16171.cpp
// https://www.acmicpc.net/problem/16171
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	string target;
	cin >> target;

	string noNumber = "";
	for (int i = 0; i < str.size(); i++) {
		if (!('0' <= str[i] && str[i] <= '9'))
			noNumber.push_back(str[i]);
	}

	bool finalIsFind = false;
	for (int i = 0; i < noNumber.size(); i++) {
		bool isFind = true;
		for (int j = 0; j < target.size(); j++) {
			if (i + j < noNumber.size() && noNumber[i + j] != target[j]) {
				isFind = false;
				break;
			}
		}

		if (isFind) {
			finalIsFind = true;
			break;
		}
	}


	if (finalIsFind)
		cout << 1;
	else
		cout << 0;
	cout << '\n';

	return 0;
}