// Baekjoon23567.cpp
// https://www.acmicpc.net/problem/23567
#include <iostream>

using namespace std;

#define INF 0x3f3f3f3f

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[10'001];
	int pSet[10'001] = { 0, }, pPrimeSet[10'001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pSet[arr[i]]++;
	}

	int ans = INF, pSetSize = k, pPrimeSetSize = 0;

	int start = 0, end = 0;
	pPrimeSet[arr[0]]++;
	pPrimeSetSize = 1;

	pSet[arr[0]]--;
	if (pSet[arr[0]] == 0)
		pSetSize--;

	while (end < n) {
		if (pPrimeSetSize == k) {
			if (pSetSize == k)
				ans = min(ans, end - start + 1);

			pPrimeSet[arr[start]]--;
			pSet[arr[start]]++;

			if (pPrimeSet[arr[start]] == 0)
				pPrimeSetSize--;

			if (pSet[arr[start]] == 1)
				pSetSize++;
			start++;
		} else {
			end++;
			if (end == n)
				break;

			pPrimeSet[arr[end]]++;
			pSet[arr[end]]--;

			if (pSet[arr[end]] == 0)
				pSetSize--;

			if (pPrimeSet[arr[end]] == 1)
				pPrimeSetSize++;
		}
	}

	if (ans == INF)
		cout << 0;
	else
		cout << ans;
	cout << '\n';

	return 0;
}