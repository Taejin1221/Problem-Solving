// Baekjoon01072_Game.cpp
// https://www.acmicpc.net/problem/1072
#include <iostream>

using namespace std;

typedef long long ll;

int main(void) {
	ll x, y;
	cin >> x >> y;

	int z = y * 100 / x;

	int start = 1, end = 1'000'000'000;
	while (start <= end) {
		int mid = (start + end) / 2;
		if ((y + mid) * 100 / (x + mid) > z)
			end = mid - 1;
		else
			start = mid + 1;
	}

	if (end == 1'000'000'000)
		cout << -1;
	else
		cout << end + 1;
	cout << endl;

	return 0;
}