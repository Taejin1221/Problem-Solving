// Baekjoon10811.cpp
// https://www.acmicpc.net/problem/10811
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
		int start, end;
		cin >> start >> end;

		for (int i = start - 1; i < end; i++) {
			temp[i] = arr[i];
		}

		for (int i = start - 1, j = end - 1; j >= start - 1; i++, j--)
			arr[j] = temp[i];
	}

	for (int i = 0;  i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}