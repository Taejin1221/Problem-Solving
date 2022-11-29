// Baekjoon25305.cpp
// https://www.acmicpc.net/problem/25305
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int score[1'000];
	for (int i = 0; i < n; i++)
		cin >> score[i];
	sort(score, score + n, greater<int>());

	cout << score[k - 1] << '\n';

	return 0;
}