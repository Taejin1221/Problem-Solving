// Baekjoon16139.cpp
// https://www.acmicpc.net/problem/16139
#include <iostream>

#include <string>

#define MAX 201

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int OFFSET = (int)'a';

	string str;
	cin >> str;

	int n = str.size();

	int prefix[26][MAX] = { { 0, } };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			prefix[j][i + 1] = prefix[j][i];
			if (str[i] - OFFSET == j)
				prefix[j][i + 1]++;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		char alpha; int start, end;
		cin >> alpha >> start >> end;

		cout << prefix[alpha - OFFSET][end + 1] - prefix[alpha - OFFSET][start] << '\n';
	}

	return 0;
}