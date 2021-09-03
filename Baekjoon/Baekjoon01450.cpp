// Baekjoon01450.cpp
// https://www.acmicpc.net/problem/1450
#include <iostream>

#include <algorithm>

#define MAX_SIZE 1'000'000

using namespace std;

typedef long long ll;

ll list[30];

void dfs(int currIdx, int endIdx, ll sum, ll arr[], int& arrIdx) {
	if (currIdx <= endIdx) {
		arr[arrIdx++] = sum + list[currIdx];
		dfs(currIdx + 1, endIdx, sum + list[currIdx], arr, arrIdx);
		dfs(currIdx + 1, endIdx, sum, arr, arrIdx);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> list[i];

	ll arr1[MAX_SIZE], arr2[MAX_SIZE];
	int size1 = 0, size2 = 0;

	dfs(0, n / 2 - 1, 0, arr1, size1);
	dfs(n / 2, n - 1, 0, arr2, size2);

	sort(arr1, arr1 + size1);
	sort(arr2, arr2 + size2);

	ll ans = 1ll;
	ans += (upper_bound(arr1, arr1 + size1, c) - arr1);
	ans += (upper_bound(arr2, arr2 + size2, c) - arr2);
	for (int i = 0; i < size1; i++)
		ans += (upper_bound(arr2, arr2 + size2, c - arr1[i]) - arr2);

	cout << ans << '\n';

	return 0;
}