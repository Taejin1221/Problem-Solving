// Baekjoon12904.cpp
// https://www.acmicpc.net/problem/12904
#include <iostream>

#include <string>

using namespace std;

string reverse(string str) {
	string result = "";

	for (int i = str.size() - 1; i >= 0; i--)
		result.push_back(str[i]);

	return result;
}

int main(void) {
	string S, T;
	cin >> S >> T;

	int sSize = S.size(), tSize = T.size();
	for (int i = tSize; i > sSize; i--) {
		char last = T.back(); T.pop_back();
		if (last == 'B')
			T = reverse(T);
	}

	if (S == T)
		cout << '1';
	else
		cout << '0';
	cout << '\n';

	return 0;
}