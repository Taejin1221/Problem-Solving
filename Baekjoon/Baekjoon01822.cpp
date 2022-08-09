// Baekjoon01822.cpp
// https://www.acmicpc.net/problem/1822
#include <iostream>

#include <set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	set<int> s;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;

		s.insert(element);
	}

	for (int i = 0; i < m; i++) {
		int element;
		cin >> element;

		if (s.find(element) != s.end()) {
			s.erase(element);
		}
	}

	cout << (int)s.size() << '\n';
	for (auto iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << ' ';
	cout << '\n';

	return 0;
}