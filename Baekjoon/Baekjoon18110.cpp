// Baekjoon18110.cpp
// https://www.acmicpc.net/problem/18110
#include <iostream>

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';

		return 0;
	}

	vector<int> diff(n);
	for (int i = 0; i < n; i++)
		cin >> diff[i];
	sort(diff.begin(), diff.end());

	int ignore = (int)round(n * 0.15);

	double sum = 0.0;
	for (int i = ignore; i < n - ignore; i++)
		sum += diff[i];

	cout << (int)round(sum / (n - ignore * 2)) << '\n';

	return 0;
}