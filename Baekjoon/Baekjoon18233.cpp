// Baekjoon18233.cpp
// https://www.acmicpc.net/problem/18233
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int n, p, e;
pii rangeDoll[20];

bool select(vector<int>& indexes, int currIdx) {
	if (indexes.size() == p) {
		pii sum = { 0, 0 };
		for (int i = 0; i < indexes.size(); i++) {
			sum.first += rangeDoll[indexes[i]].first;
			sum.second += rangeDoll[indexes[i]].second;
		}

		if (sum.first <= e && e <= sum.second)
			return true;
	} else {
		for (int i = currIdx; i < n; i++) {
			indexes.push_back(i);
			if (select(indexes, i + 1))
				return true;
			indexes.pop_back();
		}
	}

	return false;
}

int main(void) {
	cin >> n >> p >> e;
	for (int i = 0; i < n; i++)
		cin >> rangeDoll[i].first >> rangeDoll[i].second;

	vector<int> indexes;
	if (select(indexes, 0)) {
		int maxSum = 0, ans[20] = { 0, };
		for (int i = 0; i < indexes.size(); i++) {
			maxSum += rangeDoll[indexes[i]].second;
			ans[indexes[i]] = rangeDoll[indexes[i]].second;
		}

		bool isFind = false;
		for (int i = 0; i < indexes.size(); i++) {
			for (int j = rangeDoll[indexes[i]].first; j < rangeDoll[indexes[i]].second; j++) {
				if (maxSum == e) {
					isFind = true;
					break;
				}
				maxSum--, ans[indexes[i]]--;
			}

			if (isFind)
				break;
		}

		for (int i = 0; i < n; i++)
			cout << ans[i] << ' ';
	} else
		cout << -1;
	cout << '\n';

	return 0;
}