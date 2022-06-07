// Baekjoon02744.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	string ans;
	for (char& c : input) {
		if ('A' <= c && c <= 'Z')
			ans.push_back(c + 32);
		else
			ans.push_back(c - 32);
	}

	cout << ans << '\n';

	return 0;
}