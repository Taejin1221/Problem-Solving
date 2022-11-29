// Baekjoon24060.cpp
// https://www.acmicpc.net/problem/24060
#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int ans = -1, target, currSave = 0;
int arr[500'000];

void merge(int p, int q, int r) {
	vector<int> temp;

	int leftIdx = p, rightIdx = q + 1;
	while (leftIdx <= q && rightIdx <= r) {
		int save = (arr[leftIdx] < arr[rightIdx]) ? arr[leftIdx++] : arr[rightIdx++];
		currSave++;
		if (currSave == target)
			ans = save;

		temp.push_back(save);
	}

	while (leftIdx <= q) {
		currSave++;
		if (currSave == target)
			ans = arr[leftIdx];

		temp.push_back(arr[leftIdx++]);
	}

	while (rightIdx <= r) {
		currSave++;
		if (currSave == target)
			ans = arr[rightIdx];

		temp.push_back(arr[rightIdx++]);
	}

	for (int i = 0, j = p; i < temp.size(); i++, j++)
		arr[j] = temp[i];
}

void mergeSort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;

		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> target;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(0, n - 1);

	cout << ans << '\n';

	return 0;
}