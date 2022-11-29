// Baekjoon14425.cpp
// https://www.acmicpc.net/problem/14425
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<string> table;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		table.insert(str);
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		string toFind;
		cin >> toFind;

		if (table.find(toFind) != table.end())
			ans++;
	}

	cout << ans << '\n';

	return 0;
}