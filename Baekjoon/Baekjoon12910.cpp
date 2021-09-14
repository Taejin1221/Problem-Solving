// Baekjoon12910.cpp
// https://www.acmicpc.net/problem/12910
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int brand[51] = { 0, }, maxBrand = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		brand[temp]++;
		maxBrand = max(maxBrand, temp);
	}

	int result = 0, prevProduct = 1;
	for (int i = 1; i <= maxBrand; i++) {
		prevProduct *= brand[i];
		result += prevProduct;
	}

	cout << result << '\n';

	return 0;
}