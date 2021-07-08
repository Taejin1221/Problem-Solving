// Baekjoon12738.cpp
// https://www.acmicpc.net/problem/12738
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[1'000'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> list(1, arr[0]);
	for (int i = 1; i < n; i++) {
		int idx = lower_bound(list.begin(), list.end(), arr[i]) - list.begin();
		if (idx == list.size())
			list.push_back(arr[i]);
		else
			list[idx] = arr[i];
	}

	cout << list.size() << '\n';

	return 0;
}