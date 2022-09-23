// Baekjoon22252.cpp
// https://www.acmicpc.net/problem/22252
#include <iostream>

#include <map>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	long long ans = 0;
	map<string, priority_queue<int>> table;
	while (q--) {
		int oper, k;
		string name;

		cin >> oper >> name >> k;
		if (table.find(name) == table.end())
			table.insert({ name, priority_queue<int>() });

		priority_queue<int>& informations = table.find(name)->second;
		if (oper == 1) {
			for (int i = 0; i < k; i++) {
				int c;
				cin >> c;

				informations.push(c);
			}
		} else {
			for (int i = 0; i < k && !informations.empty(); i++) {
				ans += (long long)informations.top();
				informations.pop();
			}
		}
	}

	cout << ans << '\n';

	return 0;
}