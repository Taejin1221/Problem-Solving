// Baekjoon15036.cpp
// https://www.acmicpc.net/problem/15036
#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);

	double notes[17];
	notes[0] = 2.0;
	notes[1] = 1.0;
	notes[2] = 0.5;
	notes[4] = 0.25;
	notes[8] = 0.125;
	notes[16] = 0.0625;

	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		ans += notes[temp];
	}

	printf("%.6lf", ans);

	return 0;
}