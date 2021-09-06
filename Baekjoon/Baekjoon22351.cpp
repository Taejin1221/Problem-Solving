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

	int start, end;
	for (start = 1; start <= 999; start++) {
		string temp = "";
		for (end = start; end <= 999 && temp.size() < n; end++)
			temp += to_string(end);

		if (temp.size() == n && temp == str)
			break;
	}

	cout << start << ' ' << end - 1 << '\n';

	return 0;
}