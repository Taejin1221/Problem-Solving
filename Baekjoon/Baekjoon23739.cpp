// Baekjoon23739.cpp
// https://www.acmicpc.net/problem/23739
#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int time[100];
	for (int i = 0; i < n; i++)
		cin >> time[i];

	int ans = 0, timeSum = 0;
	for (int i = 0; i < n; i++) {
		timeSum += time[i];
		if (timeSum >= 30) {
			timeSum -= time[i];
			if (time[i] - (30 - timeSum) <= time[i] / 2)
				ans++;
			timeSum = 0;
		} else
			ans++;
	}

	cout << ans << '\n';

	return 0;
}