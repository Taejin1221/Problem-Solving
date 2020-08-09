// Baekjoon17219_FindPassword.cpp
// https://www.acmicpc.net/problem/17219
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	map<string, string> table;
	while ( n-- ) {
		string id, pw;
		cin >> id >> pw;

		table[id] = pw;
	}

	while ( k-- ) {
		string id;
		cin >> id;

		cout << table[id] << '\n';
	}

	return 0;
}