// Baekjoon23758.cpp
// https://www.acmicpc.net/problem/23758
// KCPC 2021 Div. 2 C
#include <iostream>

#include <algorithm>

using namespace std;

int to0(int n) {
	int result = 0;
	for (; n; result++)
		n /= 2;

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int arr[2'000'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int lgSum = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		lgSum += to0(arr[i]);
	}

	cout << lgSum - (n + 1) / 2 + 1 << '\n';

	return 0;
}