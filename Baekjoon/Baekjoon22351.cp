// Baekjoon22351.cpp
// https://www.acmicpc.net/problem/22351
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int n;
	n = str.size();

	int start = 1, end;
	bool isFind = false;
	for (start = 1; start <= 999; start++) {
		string temp = "";
		for (end = start; end <= 999 && temp.size() < n; end++) {
			temp += to_string(start);
		}

		if (temp.size() == str.size() && temp == str) {
			isFind = true;
			break;
		}

		if (isFind)
			break;
	}

	cout << start << ' ' << end;

	return 0;
}