// Baekjoon05623.cpp
// https://www.acmicpc.net/problem/5623
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int sum[1'000][1'000];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> sum[i][j];

	if (n == 2)
		cout << "1 1\n";
	else {
		vector<int> arr;

		arr.push_back((sum[0][1] + sum[0][2] - sum[1][2]) / 2);
		arr.push_back((sum[0][1] - sum[0][2] + sum[1][2]) / 2);
		arr.push_back((-sum[0][1] + sum[0][2] + sum[1][2]) / 2);

		for (int i = 4; i <= n; i++)
			arr.push_back(sum[0][i - 1] - arr[0]);

		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	return 0;
}