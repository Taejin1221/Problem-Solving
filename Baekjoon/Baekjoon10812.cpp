// Baekjoon10812.cpp
// https://www.acmicpc.net/problem/10812
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[100];
	for (int i = 1; i <= n; i++)
		arr[i - 1] = i;

	int temp[100];
	while (m--) {
		int start, end, mid;
		cin >> start >> end >> mid;

		start--, end--, mid--;

		for (int i = start; i <= end; i++) {
			temp[i] = arr[i];
		}

		int i = start;
		for (int j = mid; j <= end; i++, j++)
			arr[i] = temp[j];
		for (int j = start; j < mid; i++, j++)
			arr[i] = temp[j];
	}

	for (int i = 0;  i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}