// Baekjoon23568.cpp
// https://www.acmicpc.net/problem/23568
#include <iostream>

#include <map>

using namespace std;

using pci = pair<char, int>;
using ll = long long;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	map<int, pci> table;
	for (int i = 0; i < n; i++) {
		int currPos, distance;
		char direction;

		cin >> currPos >> direction >> distance;
		table.insert({currPos, { direction, distance }});
	}

	ll currPos;
	cin >> currPos;

	for (int i = 0; i < n; i++) {
		pci a = table.find(currPos)->second;

		if (a.first == 'L')
			currPos -= (ll)a.second;
		else
			currPos += (ll)a.second;
	}

	cout << currPos << '\n';

	return 0;
}