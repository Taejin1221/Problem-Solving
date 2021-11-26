// Baekjoon01264.cpp
// https://www.acmicpc.net/problem/1264
#include <iostream>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);
	while (str != "#") {
		int vowel = 0;
		for (int i = 0; i < (int)str.size(); i++) {
			if ('A' <= str[i] && str[i] <= 'Z')
				str[i] += 32;

			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
				vowel++;
		}

		cout << vowel << '\n';
		getline(cin, str);
	}

	return 0;
}