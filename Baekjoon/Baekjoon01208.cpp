// Baekjoon01208.cpp
// https://www.acmicpc.net/problem/1208
#include <iostream>

#include <algorithm>

#define MAX_SIZE 1'048'576

using namespace std;

int arr[40];

void dfs(int currIdx, int lastIdx, int sum, int sumList[], int& listIdx) {
	if (currIdx <= lastIdx) {
		sumList[listIdx++] = sum + arr[currIdx];
		dfs(currIdx + 1, lastIdx, sum + arr[currIdx], sumList, listIdx);
		dfs(currIdx + 1, lastIdx, sum, sumList, listIdx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int sumList1[MAX_SIZE], sumList2[MAX_SIZE];
	int list1Size = 0, list2Size = 0;

	dfs(0, n / 2 - 1, 0, sumList1, list1Size);
	dfs(n / 2, n - 1, 0, sumList2, list2Size);

	sort(sumList1, sumList1 + list1Size);
	sort(sumList2, sumList2 + list2Size);

	long long ans = 0;
	for (int i = 0; i < list1Size; i++) {
		int target = s - sumList1[i];
		ans += upper_bound(sumList2, sumList2 + list2Size, target) - lower_bound(sumList2, sumList2 + list2Size, target);
	}

	ans += upper_bound(sumList1, sumList1 + list1Size, s) - lower_bound(sumList1, sumList1 + list1Size, s);
	ans += upper_bound(sumList2, sumList2 + list2Size, s) - lower_bound(sumList2, sumList2 + list2Size, s);

	cout << ans << '\n';

	return 0;
}