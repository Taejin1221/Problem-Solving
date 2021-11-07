// Baekjoon05217.cpp
// https://www.acmicpc.net/problem/5217
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<pair<int, int>> pairs;
		for (int i = 1; i <= n / 2; i++)
			if (i != n - i)
				pairs.push_back({ i, n - i });

		cout << "Pairs for " << n << ": ";
		for (int i = 0; i < (int)pairs.size() - 1; i++)
			cout << pairs[i].first << ' ' << pairs[i].second << ", ";
		if (!pairs.empty())
			cout << pairs.back().first << ' ' << pairs.back().second;
		cout << '\n';
	}

	return 0;
}