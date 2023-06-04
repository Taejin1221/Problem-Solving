// Baekjoon07785.cpp
// https://www.acmicpc.net/problem/7785
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	set<string> hashTable;
	for (int i = 0; i < n; i++) {
		string name, log;
		cin >> name >> log;

		if (log == "enter")
			hashTable.insert(name);
		else
			hashTable.erase(name);
	}

	for (auto iter = hashTable.rbegin(); iter != hashTable.rend(); ++iter)
		cout << *iter << '\n';

	return 0;
}