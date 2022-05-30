// Baekjoon24751.cpp
// https://www.acmicpc.net/problem/24751
#include <cstdio>

int main(void) {
	int a;
	scanf("%d", &a);

	printf("%.3lf\n", 100.0 / a);
	printf("%.3lf\n", 100.0 / (100 - a));

	return 0;
}