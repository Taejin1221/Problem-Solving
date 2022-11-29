// Baekjoon25594.cpp
// https://www.acmicpc.net/problem/25594
#include <iostream>

#include <string>

using namespace std;

string HG_Phonetic_Alphabet[26] = { "aespa", "baekjoon", "cau", "debug", "edge", "firefox", "golang", "haegang", "iu", "java", "kotlin", "lol", "mips", "null", "os", "python", "query", "roka", "solvedac", "tod", "unix", "virus", "whale", "xcode", "yahoo", "zebra" };
int main(void) {
	string str;
	cin >> str;

	pair<bool, string> ans = { true, "" };
	int i = 0;
	while (i < str.size()) {
		char alphabet = str[i];

		string hg = HG_Phonetic_Alphabet[alphabet - 'a'];
		for (int j = 0; j < hg.size(); j++) {
			if (i >= str.size() || str[i++] != hg[j]) {
				ans.first = false;
				break;
			}
		}

		if (ans.first)
			ans.second.push_back(alphabet);
		else
			break;
	}

	if (ans.first) {
		cout << "It\'s HG!\n";
		cout << ans.second;
	} else
		cout << "ERROR!";
	cout << '\n';

	return 0;
}