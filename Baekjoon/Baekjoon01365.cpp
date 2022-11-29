// Baekjoon01365.cpp
// https://www.acmicpc.net/problem/1365
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int telephonePole[100'000];
	for (int i = 0; i < n; i++)
		cin >> telephonePole[i];

	vector<int> lis;
	lis.push_back(telephonePole[0]);

	for (int i = 1; i < n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), telephonePole[i]) - lis.begin();

		if (idx == lis.size())
			lis.push_back(telephonePole[i]);
		else
			lis[idx] = telephonePole[i];
	}

	cout << n - lis.size() << '\n';

	return 0;
}